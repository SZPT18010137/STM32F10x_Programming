# Reset

There are three different types of reset, defined as **System Reset**, **Power Reset** and **Backup Domain Reset**.

## 1. System Reset

A system reset sets all registers to their reset values (unless specified ohterwise in the register description) expcet the reset flags in the clock controller **CSR** register and the registers in the Backup domain.

A system reset is generated when one of the following events occurs:
1. A low level on the NRST pin (external reset)
2. Window watchdog end of count condition (WWDG reset)
3. Independent watchdog end of count condition (IWDG reset)
4. A software reset (SW reset)
5. Low-power management reset

The reset source can be identified by checking the reset flags in the Control/Status register (RCC_CSR)

**Software Reset**

The **SYSRESETREQ** bit in Cortex-M3 Application Interrupt and Reset Control register must be set to force a software reset on the device. Refer to the *STM32F10XXX Cortex M3 programming manual*

**Low-power Management Reset **

There are two ways to generate a low-power management reset:
1. Reset generated when entering standby mode: This type of reset is enabled by resetting nRST_STDBY bit in User Option Bytes. In this case, whenever a standby mode entry sequnence is successfully executed, the device is reset instead of entering standby mode.
2. Reset generated when entering stop mode: This type of reset is enabled by resetting nRST_STOP bit in User Option Bytes. In this case, whenever a stop mode entry sequnence is successfully executed, the device is reset instead of entering stop mode.

For further information on the User Option Bytes, refer to the *STM32F10xxx Flash programming manual*.
