all: pinmux-beacon.sh pinmux-robot.sh pinmux-operator.sh
clean:
	rm *.sh

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
