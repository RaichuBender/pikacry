#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*
** ROMX bank #33:
        SECTION: $4000-$69e7 ($29e8 bytes) ["Pikachu Cries 1"]
                 $4000 = PikachuCry1
                 $4002 = PikachuCry1.Start
                 $491a = PikachuCry1.End
                 $491a = PikachuCry2
                 $491c = PikachuCry2.Start
                 $4fdc = PikachuCry2.End
                 $4fdc = PikachuCry3
                 $4fde = PikachuCry3.Start
                 $59ee = PikachuCry3.End
                 $59ee = PikachuCry4
                 $59f0 = PikachuCry4.Start
                 $69e8 = PikachuCry4.End
        EMPTY: $69e8-$7fff ($1618 bytes)
        TOTAL EMPTY: $1618 bytes
*/

#define BANK_ADDR(bankNo,addr)	( bankNo ? (0x4000 * bankNo + (addr - 0x4000)) : (addr) )

#define CRY_START_ADDR			( BANK_ADDR(33,0x4000) )
#define CRY_DATA_LEN			( 0x29e87 )

size_t extract_cry(char **out_cry)
{
	FILE *yellow;
	char *crydat;

	yellow = fopen("pokeyellow.gbc", "r");

	rewind(yellow);
	fseek(yellow, CRY_START_ADDR, SEEK_CUR);

	crydat = malloc(CRY_DATA_LEN);

	fread(crydat, CRY_DATA_LEN, 1, yellow);
	fclose(yellow);

#if 0
	int c = 0;
	for(int n = 0; n<CRY_DATA_LEN; ++n)
	{
		fprintf(stdout, "%02x ", crydat[n]);
		if(++c >= 16)
		{
			c = 0;
			fputc('\n', stdout);
		}
	}
	fputc('\n', stdout);
#endif

	*out_cry = crydat;
	return CRY_DATA_LEN;
}
