GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
DEFAULT="\033[0m"

OK=1

if [ "$#" -eq 3 ] && [ "$1" == "-v" ]; then
    FLAG=1
    PROG="$2"
    DIR="$3"
elif [ "$#" -eq 2 ]; then
    FLAG=0
    PROG="$1"
    DIR="$2"
else
    echo -e "${RED}ERROR${DEFAULT}"
    exit 1
fi;

for FILE in `ls -v $DIR/*.in`; do
    BASENAME="${FILE%.[^.]*}"
    echo -e "${YELLOW}${BASENAME##*/}${DEFAULT}:"

    if [ "$FLAG" -eq 0 ]; then
        ./$PROG <$FILE >${BASENAME}.realout #$>/dev/null
    else
        ./$PROG -v <$FILE >${BASENAME}.realout 2>${BASENAME}.realerr #$>/dev/null
    fi

    if [[ $? != 0 ]]; then
        echo -e "${RED}BAD RETURN CODE{DEFAULT}"
        OK=0
    fi

    echo -n "    stdout: "
    if diff ${BASENAME}.out ${BASENAME}.realout &>/dev/null; then
        echo -e "${GREEN}OK${DEFAULT}"
        rm ${BASENAME}.realout
    else
        echo -e "${RED}BAD${DEFAULT}"
        OK=0
    fi

    if [ "$FLAG" -eq 1 ]; then
        echo -n "    stderr: "
        if diff ${BASENAME}.err ${BASENAME}.realerr &>/dev/null; then
            echo -e "${GREEN}OK${DEFAULT}"
            rm ${BASENAME}.realerr
        else
            echo -e "${RED}BAD${DEFAULT}"
            OK=0
        fi
    fi
done

if [[ $OK == 1 ]]; then
    echo -e "${GREEN}ALL TESTS PASSED SUCCESSFULLY${DEFAULT}"
else
    echo -e "${RED}SOME TESTS ARE NOT PASSED${DEFAULT}"
    exit 1
fi
