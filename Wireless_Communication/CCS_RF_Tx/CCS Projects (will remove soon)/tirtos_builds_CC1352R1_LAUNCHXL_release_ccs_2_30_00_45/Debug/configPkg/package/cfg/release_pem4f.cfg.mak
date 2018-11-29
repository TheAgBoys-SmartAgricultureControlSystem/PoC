# invoke SourceDir generated makefile for release.pem4f
release.pem4f: .libraries,release.pem4f
.libraries,release.pem4f: package/cfg/release_pem4f.xdl
	$(MAKE) -f C:\Users\Dhruva\workspace_v8\tirtos_builds_CC1352R1_LAUNCHXL_release_ccs_2_30_00_45/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Dhruva\workspace_v8\tirtos_builds_CC1352R1_LAUNCHXL_release_ccs_2_30_00_45/src/makefile.libs clean

