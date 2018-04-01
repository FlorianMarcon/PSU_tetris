#! /bin/bash


if [ $# -ne 1 ]
then
	echo "too few argument"
	exit 1
fi

RED="\e[31m"
GREEN="\e[32m"

report="report.log"

cut='1, 11p'

make re -C../../ > /dev/null

if [ $? -ne 0 ]
then
	echo "Build failed"
	exit 84
fi
cp -rf ../../tetris ./
cp -rf ./perfect/bazin ./tetris_good


echo "NEW REPORT" > $report
echo "" >> $report

echo "START MOULI"
cat $1 | while read LINE
do

	./tetris $LINE > me &
	./tetris_good $LINE > perf &

	ps | grep tetris | rev | cut -d"p" -f2- | cut -d" " -f2- | rev | cut -d" " -f2- > process

	cat process | while read LINE_PROCESS
	do
		kill $LINE_PROCESS
	done

	sed -n '1, 15p' perf > file_perfect
	rm -rf perf
	sed -n '1, 15p' me > file_me
	rm -rf me

	diff file_me file_perfect > /dev/null

	if [ $? = 1 ]
	then
		echo -e "cmd ==  $LINE" >> $report
		diff file_me file_perfect >> $report
		echo "" >> $report
		echo -e "${RED}différence for cmd : $LINE"
	else
		echo -e "${GREEN}succeed for cmd : $LINE"
	fi

done
rm -rf *~
rm -rf *#
make fclean -C../../
exit 0
