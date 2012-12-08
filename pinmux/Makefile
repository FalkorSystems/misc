all: pinmux-beacon.sh pinmux-robot.sh pinmux-operator.sh
clean:
	rm *.sh

install-robot: pinmux-robot.sh
	install -m 0755 pinmux-robot.sh /etc/init.d
	ln -sf /etc/init.d/pinmux-robot.sh /etc/rc2.d/S90pinmux

install-beacon: pinmux-beacon.sh
	install -m 0755 pinmux-beacon.sh /etc/init.d
	ln -sf /etc/init.d/pinmux-beacon.sh /etc/rc2.d/S90pinmux

install-operator: pinmux-operator.sh
	install -m 0755 pinmux-operator.sh /etc/init.d
	ln -sf /etc/init.d/pinmux-operator.sh /etc/rc2.d/S90pinmux

pinmux-robot.sh: pinmux-robot.in
	../beaglebone-pinmux-tool/bbone_pinmux_tool.rb \
	--input-file pinmux-robot.in \
	--input-format config \
	--output-format shell \
	--output-file pinmux-robot.sh

pinmux-beacon.sh: pinmux-beacon.in
	../beaglebone-pinmux-tool/bbone_pinmux_tool.rb \
	--input-file pinmux-beacon.in \
	--input-format config \
	--output-format shell \
	--output-file pinmux-beacon.sh

pinmux-operator.sh: pinmux-operator.in
	../beaglebone-pinmux-tool/bbone_pinmux_tool.rb \
	--input-file pinmux-operator.in \
	--input-format config \
	--output-format shell \
	--output-file pinmux-operator.sh
