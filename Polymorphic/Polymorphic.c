 #include <inttypes.h>
 #include <Zycore/Format.h>
 #include <Zycore/LibC.h>
 #include <Zydis/Zydis.h>
 #include <time.h>
 #include <Zycore/String.h>
 
 #pragma warning (disable : 4996)

 int DisassembleBuffer(ZydisDecoder* decoder, ZyanU8* data, ZyanUSize length)
 {
     ZydisFormatter formatter;
     ZydisFormatterInit(&formatter, ZYDIS_FORMATTER_STYLE_INTEL);
     ZydisFormatterSetProperty(&formatter, ZYDIS_FORMATTER_PROP_FORCE_SEGMENT, ZYAN_TRUE);
     ZydisFormatterSetProperty(&formatter, ZYDIS_FORMATTER_PROP_FORCE_SIZE, ZYAN_TRUE); 
     ZyanU64 runtime_address = 0x00401000;
 
     ZydisDecodedInstruction instruction;
     ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT];
     char buffer[256];
     srand(time(0));
     int counter = 0;
 
     while (ZYAN_SUCCESS(ZydisDecoderDecodeFull(decoder, data, length, &instruction, operands)))
     {
 
         ZydisFormatterFormatInstruction(&formatter, &instruction, operands,
             instruction.operand_count_visible, &buffer[0], sizeof(buffer), runtime_address,
             ZYAN_NULL);
 
 
         //ZYAN_PRINTF(" %s\t", &buffer[0]); // Disassembly printing
         //for (ZyanUSize i = 0; i < instruction.length; ++i) {
         //    printf("%02X ", data[i]); // Print opcodes
         //}
         //printf("\n");
        
    
        // Seed the random generator
         int randomBool = rand() % 2;  // Generate 0 or 1
 
         //BEGINOF MY WORKSPACE

         if (randomBool) {
             
 
             //// xor and sub
             //if ((data[0] == 0x33 || data[0] == 0x29) && instruction.length == 2) { // xor and sub 
             //   //FLAGS ARE PROBLEM!!!
 
             //    if (data[1] == 0xC0 || // xor eax, eax / sub eax, eax
             //        data[1] == 0xDB || // xor ebx, ebx / sub ebx, ebx
             //        data[1] == 0xC9 || // xor ecx, ecx / sub ecx, ecx
             //        data[1] == 0xD2 || // xor edx, edx / sub edx, edx
             //        data[1] == 0xF6 || // xor esi, esi / sub esi, esi
             //        data[1] == 0xFF || // xor edi, edi / sub edi, edi
             //        data[1] == 0xE4 || // xor esp, esp / sub esp, esp
             //        data[1] == 0xED) { // xor ebp, ebp / sub ebp, ebp
 
             //        data[0] = (data[0] == 0x33) ? 0x29 : 0x33; // Toggle between xor and sub
             //        counter++;
             //        //printf("ANALYZE! Technic 1: Transformed 0x%X 0x%X -> 0x%X 0x%X\n", data[0] == 0x33 ? 0x29 : 0x33, data[1], data[0], data[1]);
             //    }
 
             //    //data[0] = (data[0] == 0x33) ? 0x29 : 0x33; // if it is 0x33 it will make it 0x29 else 0x33. Basically change it
             //    //counter++;
             //    //printf("ANALYZE! Technic 1\n");
 
             //    goto outside;
             //}
 
                         // mov reg, 0
             if ((data[0] >= 0xB8 && data[0] <= 0xBF) && instruction.length == 5 && data[1] == 0x00 && data[2] == 0x00 && data[3] == 0x00 && data[4] == 0x00) {
 
                 // Register opcode mapping from `mov reg, 0` to `xor reg, reg`
                 const uint8_t mov_to_xor_map[8] = { 0xC0, 0xC9, 0xD2, 0xDB, 0xE4, 0xED, 0xF6, 0xFF };
 
                 data[2] = mov_to_xor_map[data[0] - 0xB8]; // Get correct register encoding
                 //printf("ANALYZE! Technic 2 -> %x, %x\n", mov_to_xor_map[data[0] - 0xB8], data[0]);
 
                 data[0] = 0x9C; // push flags, because original mov instruction didn't affect flags
                 data[1] = 0x31; // Convert to XOR
                 data[3] = 0x9D; // pop flags
                 data[4] = 0x90; // Fill remaining bytes with NOP
                 counter++;
                 goto outside;
             }
 
             // mov reg, reg//32
             if (data[0] == 0x8B && instruction.length == 2) { // mov eax, reg
 
                 if (data[1] >= 0xC1 && data[1] <= 0xC7) {
                     data[0] = data[1] - 0x70;
                 
                     data[1] = 0x58; // pop eax (same for all cases)
                     //printf("ANALYZE! Technic 3 -> %x, %x\n", data[0], data[1]);
 
                     counter++;
                 }
 
                 else if (data[1] >= 0xC8 && data[1] <= 0xCF) { // mov ecx, reg
                     data[0] = data[1] - 0x78; // Convert mov to push
                     data[1] = 0x59; // pop ecx
                     counter++;
                     //printf("WARNING! Technic 3 \n");
 
                 }
                 else if (data[1] >= 0xD0 && data[1] <= 0xD7) { // mov edx, reg
                     data[0] = data[1] - 0x80; // Convert mov to push
                     data[1] = 0x5A; // pop edx
                     counter++;
                     //printf("test edilmedi! Technic 3 \n");
                 }
                 else if (data[1] >= 0xD8 && data[1] <= 0xDF) { // mov ebx, reg
                     data[0] = data[1] - 0x88; // Convert mov to push
                     data[1] = 0x5B; // pop ebx
                     counter++;
                     //printf("test edilmedi! Technic 3 \n");
                 }
                 else if (data[1] >= 0xE8 && data[1] <= 0xEF) { // mov ebp, reg
                     data[0] = data[1] - 0x98; // Convert mov to push
                     data[1] = 0x5D; // pop ebp
                     counter++;
                     //printf("bu ebp! Technic 3 \n");
                 }
                 else if (data[1] >= 0xF0 && data[1] <= 0xF7) { // mov esi, reg
                     data[0] = data[1] - 0xA0; // Convert mov to push
                     data[1] = 0x5E; // pop esi
                     counter++;
                     //printf("bu esi! Technic 3 \n");
                 }
                 else if (data[1] >= 0xF8 && data[1] <= 0xFF) { // mov edi, reg
                     data[0] = data[1] - 0xA8; // Convert mov to push
                     data[1] = 0x5F; // pop edi
                     counter++;
                     //printf("bu edi! Technic 3 \n");
                 }
                 // If no match, skip modification
 
                 goto outside;
             }
 
 
             if (data[0] == 0x83 && data[2] == 0x01 && data[1] >= 0xC0 && data[1] <= 0xC7) { // add reg, 0x01
                 data[1] = data[1] - 0x80;
                 data[0] = 0x90;
                 data[2] = 0x90;
                 counter++;
                 printf("NOT TESTED\n");
 
                 goto outside;
             }
 
         }
         outside:
 
         //ENDOF MY WORKSPACE
 
         data += instruction.length;
         length -= instruction.length;
         runtime_address += instruction.length;
 
     }
     
     int distance = (runtime_address - runtime_address);
 
     //printf("distance -> %d\n", distance);
     
     data = data - distance; 
     printf("Counter for changed instructions -> %d \n", counter);

     //data[0] = 0x13; // EDIT AS YOU WISH
     return counter;
 }
 
 /* ============================================================================================== */
 /* Entry point                                                                                    */
 /* ============================================================================================== */
 //void readFile(LPVOID, string, DWORD);
 
 
 #include "myfunc.h"
 
 
 
 int main(int argc, char* argv[])
 {
 
     if (argc < 2) {
         printf("Usage:\n"
                "Odiemorphic.exe [file]\n"
         );
         exit(1);
     }
 
     char* fileName = argv[1];
     //printf("string -> %s\n", fileName);
 
     if (ZydisGetVersion() != ZYDIS_VERSION)
     {
         fputs("Invalid zydis version\n", ZYAN_STDERR);
         return EXIT_FAILURE;
     }
 
     int* data1;
 
     struct sender exeInfo = PeParser(fileName);
 
     data1 = exeInfo.textBaseAdress;
     int size = exeInfo.size;
     uint8_t* data = (uint8_t*)malloc(size); 
     char* getChar= (char*)data1;
 
     for (int i = 0; i < size; i++) 
         data[i] = (uint8_t)getChar[i];
     
 
     ZydisDecoder decoder;

     ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_STACK_WIDTH_32);

 
     int changedBytes = DisassembleBuffer(&decoder, &data[0], size);
     if (!changedBytes || size / 0x5000 * 25 < changedBytes || changedBytes < 12) {
 
         printf("Couldn't write anything or an error occurred:'(\nProgram will try it with entrypoint\n");
 
         exeInfo = PeParser(fileName);
 
         for (int i = 0; i < size; i++) {
             data[i] = (uint8_t)getChar[i]; // Write original file again if something written before here
         }
 
         int size2 = 0x1000;
 
         if (size - exeInfo.entryOffset > 0x10000) 
             size2 = (size - exeInfo.entryOffset) % 0x10000 + 0x3000; 

         uint8_t* data2 = (uint8_t*)malloc(size2);
 
         data1 = exeInfo.entryPoint;
 
         getChar = (char*)data1;
 
         for (int i = 0; i < size2; i++) 
             data2[i] = (uint8_t)getChar[i];
         
         if (!DisassembleBuffer(&decoder, &data2[0], size2)) {
             printf("Write Failed Again!\n");
             exit(1);
         }
         int entryHex = (int)exeInfo.entryOffset - exeInfo.rawTextoffset;
         for (int i = entryHex; i < entryHex +size2; i++) {
 
             data[i] = (uint8_t)data2[i- entryHex];
 
         }
 
     }
     //printf("%0x",data[0]);
    
     //for (int i = 0; i < size; i++) {
     //    printf("%x", data[i]);
     //}
 
     writeToFile(data,size, fileName);
     return 0;
 }
 
 /* ============================================================================================== */
 