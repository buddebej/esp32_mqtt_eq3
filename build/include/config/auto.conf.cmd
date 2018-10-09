deps_config := \
	/home/jolloux/esp/esp-idf/components/app_trace/Kconfig \
	/home/jolloux/esp/esp-idf/components/aws_iot/Kconfig \
	/home/jolloux/esp/esp-idf/components/bt/Kconfig \
	/home/jolloux/esp/esp-idf/components/esp32/Kconfig \
	/home/jolloux/esp/esp-idf/components/ethernet/Kconfig \
	/home/jolloux/esp/esp-idf/components/fatfs/Kconfig \
	/home/jolloux/esp/esp-idf/components/freertos/Kconfig \
	/home/jolloux/esp/esp-idf/components/heap/Kconfig \
	/home/jolloux/esp/esp-idf/components/libsodium/Kconfig \
	/home/jolloux/esp/esp-idf/components/log/Kconfig \
	/home/jolloux/esp/esp-idf/components/lwip/Kconfig \
	/home/jolloux/esp/esp-idf/components/mbedtls/Kconfig \
	/home/jolloux/esp/esp-idf/components/openssl/Kconfig \
	/home/jolloux/esp/esp-idf/components/pthread/Kconfig \
	/home/jolloux/esp/esp-idf/components/spi_flash/Kconfig \
	/home/jolloux/esp/esp-idf/components/spiffs/Kconfig \
	/home/jolloux/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/jolloux/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/jolloux/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/jolloux/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/jolloux/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/jolloux/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
