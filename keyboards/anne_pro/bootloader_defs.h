/* Address for jumping to bootloader on STM32 chips. */
/* It is chip dependent, the correct number can be looked up here:
 * http://www.st.com/web/en/resource/technical/document/application_note/CD00167594.pdf
 * This also requires a patch to chibios:
 *  <tmk_dir>/tmk_core/tool/chibios/ch-bootloader-jump.patch  
 * INVESTIGATE IF WE NEED THIS PATCH IS COMPATIBLE WITH STM32L1XXXC
 * ALSO, CONSIDERING WE HAVE A DFU BOOTLOADER, THE PROBABLE DOCUMENTATION IS
 * PERTINENT TO STM32L1XXXC IN THE AFOREMENTIONED DOCUMENT
 */
#define STM32_BOOTLOADER_ADDRESS 0x1FF00000
