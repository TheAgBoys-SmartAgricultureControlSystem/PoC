################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS

GEN_OPTS += C:/Users/Bennett/workspace_v8/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs/Debug/configPkg/compiler.opt
GEN_OPTS__FLAG := --cmd_file="C:/Users/Bennett/workspace_v8/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs/Debug/configPkg/compiler.opt"
GEN_CMDS += C:/Users/Bennett/workspace_v8/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs/Debug/configPkg/linker.cmd
GEN_CMDS__FLAG := -l"C:/Users/Bennett/workspace_v8/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs/Debug/configPkg/linker.cmd"

ORDERED_OBJS += \
"./CC1352P_4_LAUNCHXL.obj" \
"./CC1352P_4_LAUNCHXL_fxns.obj" \
"./POC_SoftwareTest_Rev1.obj" \
"./ccfg.obj" \
"./main_tirtos.obj" \
"../CC1352P_4_LAUNCHXL_TIRTOS.cmd" \
-l"ti/display/lib/display.aem4f" \
-l"ti/grlib/lib/ccs/m4f/grlib.a" \
-l"third_party/spiffs/lib/ccs/m4f/spiffs_cc26xx.a" \
-l"ti/drivers/rf/lib/rf_multiMode_cc13x2_v1.aem4f" \
-l"ti/drivers/lib/drivers_cc13x2_v1.aem4f" \
-l"ti/dpl/lib/dpl_cc13x2_v1.aem4f" \
$(GEN_CMDS__FLAG) \
-l"ti/devices/cc13x2_cc26x2_v1/driverlib/bin/ccs/driverlib.lib" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
POC_Test_PCB.out \

EXE_OUTPUTS__QUOTED += \
"POC_Test_PCB.out" \

BIN_OUTPUTS += \
POC_Test_PCB.hex \

BIN_OUTPUTS__QUOTED += \
"POC_Test_PCB.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "POC_Test_PCB.out"

dependents:
	-cd C:/Users/Bennett/workspace_v8/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs/Debug && $(MAKE) clean all

# Tool invocations
POC_Test_PCB.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS) C:/Users/Bennett/workspace_v8/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs/Debug/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs.lib
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=DeviceFamily_CC13X2 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"POC_Test_PCB.map" -i"C:/ti/simplelink_cc13x2_sdk_2_30_00_45/source" -i"C:/ti/simplelink_cc13x2_sdk_2_30_00_45/kernel/tirtos/packages" -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/lib" --diag_wrap=off --display_error_number --warn_sections --xml_link_info="POC_Test_PCB_linkInfo.xml" --rom_model -o "POC_Test_PCB.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

POC_Test_PCB.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/bin/armhex"  -o "POC_Test_PCB.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "CC1352P_4_LAUNCHXL.obj" "CC1352P_4_LAUNCHXL_fxns.obj" "POC_SoftwareTest_Rev1.obj" "ccfg.obj" "main_tirtos.obj" 
	-$(RM) "CC1352P_4_LAUNCHXL.d" "CC1352P_4_LAUNCHXL_fxns.d" "POC_SoftwareTest_Rev1.d" "ccfg.d" "main_tirtos.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
C:/Users/Bennett/workspace_v8/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs/Debug/tirtos_builds_CC1352P_4_LAUNCHXL_release_ccs.lib:

-include ../makefile.targets

