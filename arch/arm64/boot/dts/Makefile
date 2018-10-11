dtb-$(CONFIG_ARCH_VEXPRESS) += rtsm_ve-aemv8a.dtb foundation-v8.dtb \
				fvp-base-gicv2-psci.dtb
dtb-$(CONFIG_ARCH_VEXPRESS) += juno.dtb
dtb-$(CONFIG_ARCH_XGENE) += apm-mustang.dtb
dtb-$(CONFIG_MACH_ESPRESSO7420) += exynos7420-espresso7420.dtb
dtb-$(CONFIG_MACH_UNIVERSAL7420) += exynos7420-universal7420.dtb exynos7420-universal7420-ufs.dtb exynos7420-universal7420-ufs_rev00.dtb
dtb-$(CONFIG_MACH_SMDK7580) += exynos7580-smdk7580.dtb
dtb-$(CONFIG_CAMERA_A3X) += exynos7580-a3xelte_eur_open_00.dtb exynos7580-a3xelte_eur_open_01.dtb exynos7580-a3xelte_eur_open_02.dtb
dtb-$(CONFIG_CAMERA_A5X) += exynos7580-a5xelte_eur_open_00.dtb exynos7580-a5xelte_eur_open_01.dtb exynos7580-a5xelte_eur_open_02.dtb \
				exynos7580-a5xelte_eur_open_03.dtb exynos7580-a5xelte_eur_open_08.dtb exynos7580-a5xelte_eur_open_09.dtb
dtb-$(CONFIG_CAMERA_A7X) += exynos7580-a7xelte_eur_open_00.dtb exynos7580-a7xelte_eur_open_01.dtb exynos7580-a7xelte_eur_open_03.dtb \
				exynos7580-a7xelte_eur_open_08.dtb
dtb-$(CONFIG_CAMERA_J7) += exynos7580-j7elte_rev00.dtb exynos7580-j7elte_rev04.dtb exynos7580-j7elte_rev06.dtb
dtb-$(CONFIG_CAMERA_S5NEO) += exynos7580-s5neo_rev00.dtb exynos7580-s5neo_rev06.dtb exynos7580-s5neo_rev07.dtb exynos7580-s5neo_rev08.dtb \
				exynos7580-s5neo_rev09.dtb exynos7580-s5neo_rev11.dtb
dtb-$(CONFIG_CAMERA_GV) += exynos7580-gvwifi_rev09.dtb exynos7580-gvwifi_rev10.dtb exynos7580-gvlte_rev00.dtb exynos7580-gvlte_rev01.dtb \
				exynos7580-gvlte_rev02.dtb exynos7580-gvlte_rev09.dtb exynos7580-gvlte_rev10.dtb

dtb-$(CONFIG_MACH_UNIVERSAL5433) += exynos5433-universal5433_rev02.dtb exynos5433-universal5433.dtb
targets += dtbs

DTB_NAMES := $(subst $\",,$(CONFIG_BUILD_ARM64_APPENDED_DTB_IMAGE_NAMES))
ifneq ($(DTB_NAMES),)
DTB_LIST := $(addsuffix .dtb,$(DTB_NAMES))
else
DTB_LIST := $(dtb-y)
endif
targets += $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := dts/*.dtb *.dtb
