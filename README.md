# Raspberry Pi 4

In this repository you can find some example to use the GPIO line of the Raspberry Pi 4.

## How to use them?

1.  Install libgpiod following the official guide in this link: <a href="https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/tree" target="_blank">https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/tree</a>

2. Compile using the following command:

   ```bash
   gcc -lgpiod <name>.c
   ```

3. Try it:
   
   ```bash
   ./a.out
   ```
## BlinkLED

If you are new in Raspberry, you can start from this. It is a simple program where the led is setting on and off 20 times. 
