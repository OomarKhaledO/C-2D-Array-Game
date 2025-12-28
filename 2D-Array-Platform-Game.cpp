#include <iostream>
#include<conio.h>
#include <thread>

using namespace std;

void map(char x[][500], int aaa, int& hhh, int chero, int rhero, int sr, int mb, int c1, int slow, char usermove)
{
    //space of map.
    for (int r = 0; r < 26; r++)
    {
        for (int c = 0; c < 500; c++)
        {
            x[r][c] = ' ';
        }
    }

    //limits of map.
    int r = 4;
    for (int c = 0; c < 500; c++) //up line.
    {
        x[r][c] = '_';
        if (c == 185)
        {
            x[r][c] = '1';
        }
    }
    //floor.
    for (int r = 23; r < 24; r++)
    {
        for (int c = 0; c < 500; c++)
        {
            x[r][c] = '_';
        }
    }


    //level 1.
    for (int r = 23; r < 24; r++) {
        for (int c = 0; c < 500; c++) {
            if (c % 10 == 0) x[r][c] = '*';  // Cracked floor
            else if (c % 15 == 0) x[r][c] = 'x'; // Bone-like crack
            else x[r][c] = '_';  // Regular floor
        }
    }

    // Cauldron in the corner
    for (int r = 15; r < 17; r++)
    {
        for (int c = 40; c < 45; c++)
        {
            x[r][c] = 'O'; // Cauldron
        }
    }
    for (int r = 16; r < 17; r++)
    {
        for (int c = 41; c < 44; c++)
        {
            x[r][c] = '@'; // bubbling potion
        }
    }

    // Candles lit on the floor and walls 
    for (int r = 18; r < 20; r++)
    {
        for (int c = 10; c < 15; c++)
        {
            if (c % 2 == 0)
            {
                x[r][c] = '|';  // Candle stick
            }
        }
    }
    for (int r = 16; r < 18; r++)
    {
        for (int c = 70; c < 75; c++)
        {
            if (r % 2 == 0)
            {
                x[r][c] = '|';  // More candles
            }
        }
    }

    // Bookshelves on the sides
    for (int r = 10; r < 12; r++)
    {
        for (int c = 5; c < 15; c++)
        {
            x[r][c] = '#';  // Bookshelf outline
        }
    }

    // Arcane Symbols on the Walls
    for (int r = 8; r < 10; r++)
    {
        for (int c = 35; c < 45; c++)
        {
            if (c % 3 == 0)
            {
                x[r][c] = '*';  // Magical symbols
            }
        }
    }

    // Flickering fireplace 
    for (int r = 12; r < 14; r++)
    {
        for (int c = 60; c < 80; c++)
        {
            if (c % 10 == 0)
            {
                x[r][c] = '+';
            }
            else
            {
                x[r][c] = '-';  // Creating a fireplace
            }
        }
    }

    // Dark corner
    for (int r = 10; r < 12; r++)
    {
        for (int c = 52; c < 63; c++)
        {
            if (r % 2 == 0)
            {
                x[r][c] = 'x';  // Haunted corner

            }
        }
    }
    x[11][53] = 'o';
    x[11][55] = 'o';
    x[11][57] = 'o';
    x[11][59] = 'o';
    x[11][61] = 'o';
    for (int r = 4; r < 10; r++)
    {
        x[r][57] = '|';
    }
    // Window to the outside 
    for (int r = 4; r < 5; r++)
    {
        for (int c = 100; c < 120; c++)
        {
            if (r == 3 && c % 2 == 0)
            {
                x[r][c] = '@';  // Moon symbol
            }
            else
            {
                x[r][c] = '#';  // Dark window
            }
        }
    }
    //obstacle.
    for (int r = 22; r < 24; r++)
    {
        for (int c = 95; c < 101; c++)
        {
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
        }
    }
    for (int r = 23; r < 24; r++)
    {
        for (int c = 82; c < 86; c++)
        {
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
            c++;
            x[r][c] = 24;
        }
    }
    for (int r = 23; r < 24; r++)
    {
        for (int c = 69; c < 73; c++)
        {
            x[r][c] = 24;
        }
    }

    // function of obstacles

    for (int c = 95; c < 101; c++)
    {
        if (chero == c && rhero == 21)
        {
            hhh = 1; // hero died.
        }
    }
    for (int c = 82; c < 86; c++)
    {
        if (chero == c && rhero == 21)
        {
            hhh = 1; // hero died.
        }
    }
    for (int c = 69; c < 73; c++)
    {
        if (chero == c && rhero == 21)
        {
            hhh = 1; // hero died.
        }
    }
    if (chero > 90)
    {
        x[11][97] = 'w';
        x[11][98] = 'e';
        x[11][99] = ' ';
        x[11][100] = 'l';
        x[11][101] = 'i';
        x[11][102] = 'e';
        x[11][103] = 'd';
        x[11][104] = ' ';
        x[11][105] = 't';
        x[11][106] = 'h';
        x[11][107] = 'e';
        x[11][108] = ' ';
        x[11][109] = 'c';
        x[11][110] = 'l';
        x[11][111] = 'o';
        x[11][112] = 'n';
        x[11][113] = 'e';
        x[11][114] = 's';
        x[11][115] = ' ';
        x[11][116] = 'a';
        x[11][117] = 'r';
        x[11][118] = 'e';
        x[11][119] = ' ';
        x[11][120] = 'n';
        x[11][121] = 'o';
        x[11][122] = 't';
        x[11][123] = ' ';
        x[11][124] = 'h';
        x[11][125] = 'e';
        x[11][126] = 'r';
        x[11][127] = 's';
        x[11][128] = ' ';
        x[11][129] = 'T';
        x[11][130] = 'H';
        x[11][131] = 'E';
        x[11][132] = 'Y';
        x[11][133] = '\'';
        x[11][134] = 'R';
        x[11][135] = 'E';
        x[11][136] = ' ';
        x[11][137] = 'Y';
        x[11][138] = 'O';
        x[11][139] = 'U';
        x[11][140] = 'R';
        x[11][141] = 'S';
        x[11][142] = '.';
        x[11][143] = '.';
        x[11][144] = '.';
        x[12][145] = 'u';
        x[12][146] = 's';
        x[12][147] = 'e';
        x[12][148] = ' ';
        x[12][149] = 't';
        x[12][150] = 'h';
        x[12][151] = 'e';
        x[12][152] = ' ';
        x[12][153] = 'm';
        x[12][154] = 'a';
        x[12][155] = 'c';
        x[12][156] = 'e';
        x[13][157] = 'P';
        x[13][158] = 'R';
        x[13][159] = 'O';
        x[13][160] = 'P';
        x[13][161] = 'E';
        x[13][162] = 'R';
        x[13][163] = 'L';
        x[13][164] = 'Y';
    }
    //el selm.
    for (int r = 23; r < 24; r++)
    {
        for (int c = 130; c < 131; c++)
        {
            x[r][c] = 186;
        }
    }
    for (int r = 22; r < 23; r++)
    {
        for (int c = 130; c < 135; c++)
        {
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
        }
    }
    for (int r = 21; r < 22; r++)
    {
        for (int c = 135; c < 136; c++)
        {
            x[r][c] = 186;
        }
    }
    for (int r = 20; r < 21; r++)
    {
        for (int c = 135; c < 140; c++)
        {
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
            c++;
            x[r][c] = 205;
        }
    }
    for (int r = 19; r < 20; r++)
    {
        for (int c = 140; c < 141; c++)
        {
            x[r][c] = 186;
        }
    }
    for (int r = 18; r < 19; r++)
    {
        for (int c = 140; c < 160; c++)
        {
            x[r][c] = 205;
        }
    }
    for (int r = 4; r < 5; r++) x[r][156] = '|';
    for (int r = 5; r < 6; r++) x[r][156] = 'o';
    for (int r = 6; r < 7; r++) x[r][156] = '|';
    for (int r = 7; r < 8; r++) x[r][156] = '+';
    for (int r = 7; r < 8; r++) x[r][155] = '/';
    for (int r = 7; r < 8; r++) x[r][157] = '\\';
    for (int r = 8; r < 9; r++) x[r][156] = '|';
    for (int r = 9; r < 10; r++) x[r][155] = '/';
    for (int r = 9; r < 10; r++) x[r][157] = '\\';
    for (int r = 4; r < 5; r++) x[r][165] = '|';
    for (int r = 5; r < 6; r++) x[r][165] = 'o';
    for (int r = 6; r < 7; r++) x[r][165] = '|';
    for (int r = 7; r < 8; r++) x[r][165] = '+';
    for (int r = 7; r < 8; r++) x[r][164] = '/';
    for (int r = 7; r < 8; r++) x[r][166] = '\\';

    // Potion rack (rows 16–17, columns 172–180)
    for (int r = 11; r < 12; r++)
    {
        for (int c = 172; c < 180; c++)
        {
            if (c % 2 == 0) x[r][c] = '!'; // potion bottles
            else x[r][c] = '~';            // fumes or effect
        }
    }
    for (int c = 172; c < 180; c++) x[12][c] = '='; // shelf base

    for (int r = 4; r < 5; r++) x[r][175] = '|';
    for (int r = 5; r < 6; r++) x[r][175] = 'o';
    for (int r = 6; r < 7; r++) x[r][175] = '|';
    for (int r = 7; r < 8; r++) x[r][175] = '+';
    for (int r = 8; r < 9; r++) x[r][175] = '|';
    //level 2;
    //floor of door.
    for (int r = 18; r < 19; r++)
    {
        for (int c = 160; c < 170; c++)
        {
            x[r][c] = 205;
        }
        for (int c = 170; c < 171; c++) // selm.
        {
            x[r][c] = 'H';
            r++;
            x[r][c] = 'H';
            r++;
            x[r][c] = 'H';
            r++;
            x[r][c] = 'H';
            r++;
            x[r][c] = 'H';
        }
    }

    // gun.
    if (aaa == 0)
    {


        for (int r = 21; r < 22; r++) {
            for (int c = 185; c < 186; c++) {
                x[r][c] = '<';
                c++;
                x[r][c] = 'O';  // arcane core
                c++;
                x[r][c] = '>';
                c++;
            }
        }
        for (int r = 22; r < 23; r++) {
            for (int c = 185; c < 186; c++) {
                x[r][c] = ' ';
                c++;
                x[r][c] = '|';
            }
        }


    }
    if (aaa != 0)
    {
        int r = 5;
        int c = 200;

        // Top border
        for (int i = 0; i < 15; i++)
        {
            x[r][c + i] = '#';
        }


        x[r + 1][c] = '#'; x[r + 1][c + 14] = '#';

        x[r + 2][c] = '#'; x[r + 2][c + 14] = '#';
        x[r + 2][c + 5] = ' '; x[r + 2][c + 6] = '/'; x[r + 2][c + 7] = '\\'; x[r + 2][c + 8] = ' ';

        x[r + 3][c] = '#'; x[r + 3][c + 14] = '#';
        x[r + 3][c + 5] = '/'; x[r + 3][c + 6] = '_'; x[r + 3][c + 7] = '_'; x[r + 3][c + 8] = '\\';

        x[r + 4][c] = '#'; x[r + 4][c + 14] = '#';
        x[r + 4][c + 5] = '('; x[r + 4][c + 6] = 'O'; x[r + 4][c + 7] = 'O'; x[r + 4][c + 8] = ')';

        x[r + 5][c] = '#'; x[r + 5][c + 14] = '#';
        x[r + 5][c + 5] = '|'; x[r + 5][c + 6] = '/'; x[r + 5][c + 7] = '\\'; x[r + 5][c + 8] = '|';

        x[r + 6][c] = '#'; x[r + 6][c + 14] = '#';
        x[r + 6][c + 6] = '_'; x[r + 6][c + 7] = '|'; x[r + 6][c + 8] = '_';

        x[r + 7][c] = '#'; x[r + 7][c + 14] = '#';

        x[r + 8][c] = '#'; x[r + 8][c + 14] = '#';
        x[r + 8][c + 5] = 'S'; x[r + 8][c + 6] = 'H'; x[r + 8][c + 7] = 'R'; x[r + 8][c + 8] = 'I'; x[r + 8][c + 9] = 'M'; x[r + 8][c + 10] = 'P';

        x[r + 9][c] = '#'; x[r + 9][c + 14] = '#';
        x[r + 9][c + 6] = 'T'; x[r + 9][c + 7] = 'I'; x[r + 9][c + 8] = 'M'; x[r + 9][c + 9] = 'E';

        x[r + 10][c] = '#'; x[r + 10][c + 14] = '#';


        for (int i = 0; i < 15; i++)
        {
            x[r + 11][c + i] = '#';
        }

    }
    if (chero > 220)
    {
        int r = 11, c = 221;
        x[r][c] = 's';
        x[r][c] = 's';
        x[r][c] = 's';
        x[r][c + 1] = 'o';
        x[r][c + 2] = ' ';
        x[r][c + 3] = 'm';
        x[r][c + 4] = 'a';
        x[r][c + 5] = 'n';
        x[r][c + 6] = 'y';
        x[r][c + 7] = ' ';
        x[r][c + 8] = 's';
        x[r][c + 9] = 'p';
        x[r][c + 10] = 'e';
        x[r][c + 11] = 'l';
        x[r][c + 12] = 'l';
        x[r][c + 13] = 's';

        x[r + 1][c + 7] = 'u';
        x[r + 1][c + 8] = 's';
        x[r + 1][c + 9] = 'e';
        x[r + 1][c + 10] = ' ';
        x[r + 1][c + 11] = 'm';
        x[r + 1][c + 12] = 'a';
        x[r + 1][c + 13] = 'g';
        x[r + 1][c + 14] = 'i';
        x[r + 1][c + 15] = 'c';
        x[r + 1][c + 16] = ' ';
        x[r + 1][c + 17] = 'c';
        x[r + 1][c + 18] = 'a';
        x[r + 1][c + 19] = 'r';
        x[r + 1][c + 20] = 'p';
        x[r + 1][c + 21] = 'e';
        x[r + 1][c + 22] = 't';
    }
    //level2.
    //floor of door of elevator.

    for (int r = 14; r < 15; r++)
    {
        for (int c = 274; c < 310; c++)
        {
            x[r][c] = '_';
        }

    }

    //multibullet.
    if (mb == 0)
    {
        for (int r = 13; r < 14; r++)
        {
            for (int c = 285; c < 286; c++)
            {
                x[r][c] = '{';
            }
        }
    }
    if (mb != 0)
    {
        x[8][277] = 'u';
        x[8][278] = 's';
        x[8][279] = 'e';
        x[8][280] = ' ';
        x[8][281] = 't';
        x[8][282] = 'h';
        x[8][283] = 'e';
        x[8][284] = ' ';
        x[8][285] = 's';
        x[8][286] = 'h';
        x[8][287] = 'a';
        x[8][288] = 'r';
        x[8][289] = 'd';
        x[9][283] = ' ';
        x[9][284] = 't';
        x[9][285] = 'o';
        x[9][286] = ' ';
        x[9][287] = 'o';
        x[9][288] = 'f';
        x[9][289] = 'f';
        x[9][290] = ' ';
        x[9][291] = ' ';
        x[9][292] = '<';
        x[9][293] = ' ';
        x[9][294] = '{';
        x[9][295] = ' ';
        x[9][296] = '>';

        x[10][290] = 't';
        x[10][291] = 'h';
        x[10][292] = 'e';
        x[10][293] = ' ';
        x[10][294] = 's';
        x[10][295] = 'p';
        x[10][296] = 'e';
        x[10][297] = 'l';
        x[10][298] = 'l';

        if (usermove == 'f')
        {
            x[8][277] = ' ';
            x[8][278] = ' ';
            x[8][279] = ' ';
            x[8][280] = ' ';
            x[8][281] = ' ';
            x[8][282] = ' ';
            x[8][283] = ' ';
            x[8][284] = ' ';
            x[8][285] = ' ';
            x[8][286] = ' ';
            x[8][287] = ' ';
            x[8][288] = ' ';
            x[8][289] = ' ';
            x[9][283] = ' ';
            x[9][284] = ' ';
            x[9][285] = ' ';
            x[9][286] = ' ';
            x[9][287] = ' ';
            x[9][288] = ' ';
            x[9][289] = ' ';

            x[9][292] = ' ';
            x[9][293] = ' ';
            x[9][294] = ' ';
            x[9][295] = ' ';
            x[9][296] = ' ';


            x[10][290] = ' ';
            x[10][291] = ' ';
            x[10][292] = ' ';
            x[10][293] = ' ';
            x[10][294] = ' ';
            x[10][295] = ' ';
            x[10][296] = ' ';
            x[10][297] = ' ';
            x[10][298] = ' ';
            x[8][284] = 'T';
            x[8][285] = 'H';
            x[8][286] = 'E';
            x[8][287] = ' ';
            x[8][288] = 'S';
            x[8][289] = 'H';
            x[8][290] = 'A';
            x[8][291] = 'R';
            x[8][292] = 'D';


            x[10][292] = 'I';
            x[10][293] = 'D';
            x[10][294] = 'I';
            x[10][295] = 'O';
            x[10][296] = 'T';

        }
    }
    if (chero > 325)
    {
        int r = 14, c = 329;
        x[r][c] = 'u';
        x[r][c + 1] = 's';
        x[r][c + 2] = 'e';
        x[r][c + 3] = ' ';
        x[r + 1][c] = 's';
        x[r + 1][c + 1] = 'p';
        x[r + 1][c + 2] = 'e';
        x[r + 1][c + 3] = 'e';
        x[r + 1][c + 4] = 'd';
        x[r + 1][c + 5] = ' ';
        x[r + 1][c + 7] = '<';
        x[r + 1][c + 8] = ' ';
        x[r + 1][c + 9] = '&';
        x[r + 1][c + 10] = ' ';
        x[r + 1][c + 11] = '>';
        x[r + 2][c] = 'p';
        x[r + 2][c + 1] = 'o';
        x[r + 2][c + 2] = 't';
        x[r + 2][c + 3] = 'i';
        x[r + 2][c + 4] = 'o';
        x[r + 2][c + 5] = 'n';
        x[r + 2][c + 6] = '!';
    }
    //speed run
    if (sr == 0)
    {
        for (int r = 22; r < 23; r++)
        {
            for (int c = 330; c < 331; c++)
            {
                x[r][c] = '&';
            }
        }
    }
    if (slow == 2)
    {
        x[15][chero + 20] = 'T';
        x[15][chero + 21] = 'O';
        x[15][chero + 22] = 'O';
        x[15][chero + 23] = ' ';
        x[15][chero + 24] = 'S';
        x[15][chero + 25] = 'L';
        x[15][chero + 26] = 'O';
        x[15][chero + 27] = 'W';
        x[15][chero + 28] = ' ';
        x[15][chero + 29] = 'o';
        x[16][chero + 30] = 'v';
        x[15][chero + 31] = 'o';
    }
}


void minilaser(int& h, char x[][500], int chero, int claser, int laserState, int rlaser[], int rhero)
{
    if (laserState == 1) // Laser ON
    {
        // laser
        for (int r = 15; r < 24; r++)
        {
            x[r][claser] = 'U';
        }

        // kill hero
        if (chero == claser)
        {
            for (int i = 0; i < 10; i++)
            {
                if (rlaser[i] == rhero)
                {
                    h = 1;
                }
            }

        }
    }
    else // Laser OFF
    {
        for (int r = 15; r < 24; r++)
        {
            if (x[r][claser] == 'U')
            {
                x[r][claser] = ' '; // delete laser
            }
        }
    }
}
void laser(int& h, char x[][500], int chero, int claser, int laserState)
{
    if (laserState == 1) // Laser ON
    {
        // laser
        for (int r = 5; r < 24; r++)
        {
            x[r][claser] = 219;
        }

        // kill hero
        if (chero == claser)
        {
            h = 1;
        }
    }
    else // Laser OFF
    {
        for (int r = 5; r < 24; r++)
        {
            if (x[r][claser] == 219)
            {
                x[r][claser] = ' '; // delete laser
            }
        }
    }
}

void drawElevator(char x[][500], int Rele, int Cele) {
    for (int i = 0; i < 8; i++)
    {
        x[Rele][Cele + i] = '=';
    }
}
void moveElevator(int& direle, int& Rele, int& rhero, int chero, int Cele)
{
    // Hero is standing on the elevator if their legs are exactly above it
    if (rhero + 2 == Rele && chero >= Cele && chero < Cele + 5)
    {
        if (direle == 1)
        {
            if (Rele > 5)
            {
                Rele--;
                if (rhero > 0)
                {
                    rhero--;
                }
            }
            else
            {
                direle = 0;
            }
        }
        else if (direle == 0)
        {
            if (Rele < 26)
            {
                Rele++;
                if (rhero < 21)
                {
                    rhero++;
                }
            }
            else
            {
                direle = 1;
            }
        }
    }
    else if (direle == 1)
    {
        if (Rele > 8)
        {
            Rele--;
        }
        else
        {
            direle = 0;
        }
    }
    else if (direle == 0)
    {
        if (Rele < 26)
        {
            Rele++;
        }
        else
        {
            direle = 1;
        }
    }
}


void fire(char x[][500], int rHero, int cHero, int dir, int gnblt[20])
{
    for (int i = 0; i < 20; i += 2)
    {
        if (gnblt[i] == -1)
        {
            gnblt[i] = rHero + 1;         // bullet row (a bit lower than hero head)
            if (dir == 0)
            {
                gnblt[i + 1] = cHero + 2;
            }
            break;
        }
    }
}
void moveBullets(char x[][500], int gnblt[20], int& cenemy, int& eee, int& cenemy2, int& eee2, int renemy, int& me2, int& ct1, int& ct2)
{
    for (int i = 0; i < 20; i += 2) {
        if (gnblt[i] != -1)
        {
            x[gnblt[i]][gnblt[i + 1]] = ' '; // erase old
            if (x[gnblt[i]][gnblt[i + 1] + 1] == ' ')
            {
                gnblt[i + 1]++;
                x[gnblt[i]][gnblt[i + 1]] = 'o';
                if ((gnblt[i + 1] >= cenemy && gnblt[i + 1] <= cenemy + 2) || (gnblt[i + 1] + 2 >= cenemy && gnblt[i + 1] <= cenemy))
                {
                    ct1++;
                    if (ct1 >= 4)
                    {
                        eee = 1;
                        me2 = 1;
                    }
                    gnblt[i] = -1;
                    gnblt[i + 1] = -1;
                }
                if ((gnblt[i + 1] >= cenemy2 && gnblt[i + 1] <= cenemy2 + 2) || (gnblt[i + 1] + 2 >= cenemy2 && gnblt[i + 1] <= cenemy2))
                {
                    ct2++;
                    if (ct2 >= 4)
                    {
                        eee2 = 1;
                    }
                    gnblt[i] = -1;
                    gnblt[i + 1] = -1;
                }
            }
            else
            {
                gnblt[i] = -1;
                gnblt[i + 1] = -1;
            }
        }
    }
}



void fireMultiBullets(char x[][500], int rHero, int cHero, int mb, int rvblt[20])
{
    if (mb == 1)
    {
        for (int i = 0; i < 20; i += 2)
        {
            if (rvblt[i] == -1)
            {
                rvblt[i] = rHero;
                rvblt[i + 1] = cHero + 2;
                break;
            }
        }
        for (int i = 0; i < 20; i += 2)
        {
            if (rvblt[i] == -1)
            {
                rvblt[i] = rHero + 1;       // second bullet row
                rvblt[i + 1] = cHero + 2;
                break;
            }
        }
    }
}
void moveMultiBullets(char x[][500], int rvblt[20])
{
    for (int i = 0; i < 20; i += 2)
    {
        if (rvblt[i] != -1)
        {
            x[rvblt[i]][rvblt[i + 1]] = ' '; // erase old
            if (x[rvblt[i]][rvblt[i + 1] + 1] == ' ')
            {
                rvblt[i + 1]++;
                x[rvblt[i]][rvblt[i + 1]] = '{';
            }
            else
            {
                rvblt[i] = -1;
                rvblt[i + 1] = -1;
            }
        }
    }
}
void laserGate(int& h, char x[][500], int rvblt[20], int& cr, int chero, int& ct)
{
    if (cr == 0)
    {
        for (int i = 0; i < 20; i += 2)
        {
            if (rvblt[i] != -1 && rvblt[i + 1] == 310 && rvblt[i] >= 12 && rvblt[i] <= 14)
            {
                ct++;
                if (ct == 5)
                {
                    cr = 2; // deactivate gate
                }
                rvblt[i] = -1;
                rvblt[i + 1] = -1;
            }
        }
    }
    if (cr != 2)
    {
        for (int r = 5; r < 15; r++)
        {
            x[r][310] = 'I';
        }
        // did i touch the laser
        if (chero == 310)
        {
            h = 1;
        }
    }
}
void drawhero(int rhero, int chero, int hhh, char x[][500], int s)
{
    if (hhh == 0)
    {
        if (s == 0)
        {
            x[rhero][chero] = 2;
            x[rhero + 1][chero] = 219;
            x[rhero + 2][chero] = 234;
            x[rhero + 1][chero + 1] = ')';
        }

        if (s == 1)
        {
            x[rhero][chero] = 2;
            x[rhero + 1][chero] = 219;
            x[rhero + 2][chero] = 234;
            x[rhero + 1][chero - 1] = '(';

        }


    }


}

void movehero(int& rHero, int& cHero, char userMove, int& colum, int& aaa, int hhh, char x[][500], int& sr, int& mb, int& dir, int gnblt[], int rvblt[])
{
    if (hhh == 0)
    {
        if (userMove == 'c')
        {
            if (x[rHero - 1][cHero] == 'H' || x[rHero + 3][cHero] == 'H')
            {
                rHero--;
            }
        }

        if (userMove == 'w' && cHero != 'H')
        {
            if (rHero > 17)
            {
                rHero -= 5;
                cHero += 5;
                colum += 5;
            }

        }
        if (userMove == 's')
        {
            if (x[rHero + 3][cHero] == 'H' || x[rHero + 4][cHero] == 'H')
            {
                rHero++;
            }
        }
        /*
        if (userMove == 's')
        {
            if (rHero > 16 && cHero > 5)
            {
                rHero -= 5;
                cHero -= 5;
                colum -= 5;
            }

        }
        */
        if (userMove == 'a')
        {
            if (cHero > 5)
            {
                dir = 1;
                cHero -= 1;
                colum -= 1;
            }
        }
        if (userMove == 'd')
        {
            if (x[rHero + 1][cHero + 2] != 186)
            {
                dir = 0;
                cHero += 1;
                colum += 1;

            }

        }


        if (cHero == 185) // gun disappear.
        {

            aaa = 1;
        }
        if (userMove == 'f' && aaa == 1)
        {
            fire(x, rHero, cHero, dir, gnblt);
        }
        if (userMove == 'g')
        {
            fireMultiBullets(x, rHero, cHero, mb, rvblt);
        }

        if (cHero == 330 && rHero == 21) // speed run disapear and activate
        {
            sr = 1;
        }

        if (sr == 1)
        {
            if (userMove == 'r')
            {
                cHero = cHero + 3;
                colum = colum + 3;
            }
        }

        if (cHero == 285 && rHero < 19) // multibullet icon disapear and activate.
        {
            mb = 1;
        }

    }

}



void drawenemy1(int renemy, int cenemy, int eee, char x[][500], int ct1)
{
    if (eee == 0)
    {
        x[renemy][cenemy] = 2;
        x[renemy + 1][cenemy] = 219;
        x[renemy + 2][cenemy] = 234;

        // Show hit count 
        if (ct1 > 0 && ct1 <= 4)
        {
            x[renemy - 1][cenemy] = ct1 + '0';
        }
    }

}

void moveenemy1(int& cenemy, int aaa, int chero, int& hhh, int& eee, int rhero, int renemy)
{
    if (aaa == 1) // hero take gun
    {
        for (int k = 0; k < 1; k++)
        {
            cenemy--;
        }
    }
    if (cenemy == chero && eee == 0 && rhero == renemy) //There was a glitch 
    {
        hhh = 1;
    }

}

void drawenemy2(int renemy2, int cenemy2, int& eee2, char x[][500], int ct2)
{
    if (eee2 == 0)
    {
        x[renemy2][cenemy2] = 2;
        x[renemy2 + 1][cenemy2] = 219;
        x[renemy2 + 2][cenemy2] = 219;
        x[renemy2 + 3][cenemy2] = 234;
        if (ct2 > 0 && ct2 <= 4)
        {
            x[renemy2 - 1][cenemy2] = ct2 + '0';  // draw number above enemy
        }
    }
}

void moveenemy2(int& cenemy2, int aaa, int chero, int& hhh, int me2, int eee, int rhero, int renemy)
{
    if (me2 == 1)
    {
        if (aaa == 1)
        {
            for (int k = 0; k < 1; k++)
            {
                cenemy2 -= 2;
            }

        }
    }
    if (chero == cenemy2 && rhero == renemy)
    {
        hhh = 1;
    }

}

void gravity(char x[][500], int& rHero, int& chero)
{



    if (chero < 266 || chero>274)
    {


        if (x[rHero + 2][chero] == ' ')
        {
            rHero++;
        }
        if (x[rHero][chero + 2] != ' ')
        {
        }

    }
}

void screen(int colum, int chero, char x[][500], int& b, char level, int aaa, int cenemy, int& eee, int cenemy2, int& eee2, int& me, int GameOver, char Score, char Lifes, int h, int c
    , int& b2)
{
    system("cls");
    if (GameOver == 0)
    {
        //score indicator
        if (aaa == 1 && eee2 == 0)
        {
            Score = 'C';
        }
        if (aaa == 0)
        {
            Score = 'D';
        }
        if (eee2 == 1)
        {
            Score = 'A';
        }
        if (h == 1)
        {
            Lifes = 'O';
        }


        // level indicator.
        if (aaa == 1 && eee2 == 0)
        {
            level = 'B';
        }
        if (aaa == 0)
        {
            level = 'A';
        }
        if (eee2 == 1)
        {
            level = 'C';
        }

        for (int r = 2; r < 3; r++)
        {
            for (int c = 30; c < 33; c++)
            {
                x[r][c] = 'L';
                c++;
                x[r][c] = 'I';
                c++;
                x[r][c] = 'V';
                c++;
                x[r][c] = 'E';
                c++;
                x[r][c] = 'S';
                c++;
                x[r][c] = ':';
                c += 2;
                x[r][c] = Lifes;

            }
            for (int c = 40; c < 43; c++)
            {
                x[r][c] = 'S';
                c++;
                x[r][c] = 'C';
                c++;
                x[r][c] = 'O';
                c++;
                x[r][c] = 'R';
                c++;
                x[r][c] = 'E';
                c++;
                x[r][c] = ':';
                c += 2;
                x[r][c] = Score;

            }
            for (int c = 60; c < 63; c++)
            {
                x[r][c] = 'L';
                c++;
                x[r][c] = 'E';
                c++;
                x[r][c] = 'V';
                c++;
                x[r][c] = 'E';
                c++;
                x[r][c] = 'L';
                c++;
                x[r][c] = ':';
                c += 2;
                x[r][c] = level;

            }
            for (int c = 0; c < 68; c++)
            {
                cout << x[r][c];
            }
        }
        // scrolling . 
        for (int r = 3; r < 26; r++)
        {
            for (int c = chero - 5; c < colum; c++)
            {
                cout << x[r][c];
            }
            cout << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "    YES" << endl;
        cout << "        THIS IS WHERE YOU STARTED" << endl;
        cout << "     YOU CAN NOT ESCAPE" << endl;
        cout << endl;
        string witchWithShrimp[14] = {
      "       /\\    ",
        "      /__\\   ",
        "     ( QQ )     YOU    WILL    ",
        "     |/\\/|                    ALWAYS    ",
        "     _||_                                 BE    ",
        "    /_____\\                                     MINE     ",
        "   (      )  ",
        "  /|      |\\ ",
        " /_|  u   |_\\ ",
        "   |      |  ",
        "   |______|  ",
        "  /_|____|_\\ ",
        "    ||  ||   ",
        "    []  []   "
        };

        for (int i = 0; i < 14; ++i) {
            cout << "      " << witchWithShrimp[i] << endl;
        }
    }

}




void drawthorns(char x[][500], int cThorns, int rThorns)
{
    for (int r = rThorns; r < 23; r++)
    {
        x[r][cThorns] = 026;
    }
}

void movethorns(char x[][500], int& cthorns, int chero, int& hhh, int& slow)
{
    if (chero >= 355 && cthorns < 500)
    {
        cthorns = cthorns + 3;

        if ((cthorns >= chero && cthorns <= chero + 2) || (cthorns + 2 >= chero && cthorns <= chero))
        {
            hhh = 1;
            slow = 2;

        }
    }
}


void Gameover(int& GameOver, int chero)
{
    for (int i = 460; i < 500; i++)
    {
        if (chero == i)
        {
            GameOver = 1;
        }
    }
}
int main()
{
    //hero
    int rhero = 21;
    int chero = 5;
    int colum = 80;
    // ......
    char umove;
    //bullet
    int gnblt[20];
    for (int i = 0; i < 20; i++) gnblt[i] = -1;
    // ....
    //multibullet
    int rvblt[20];
    for (int i = 0; i < 20; i++) rvblt[i] = -1;
    // ....
    int dir = 0; // 0 = right, 1 = left
    //elevator
    int relevator = 21;
    int celevator = 266;
    int direle = 1;
    int eletoggle = 0;
    // ....
    char Score = 'D';

    //coins.
    int c1 = 0;



    //move of hero when it is back way.

    int s = 0;
    //laser gate
    int mct = 0; // multibullets count
    int cr = 0;
    //mini lasers
    int mrlaser[10] = { 15,16,17,18,19,20,21,22,23,24 };
    int mclaser = 277, mlaserState = 1;
    int mc2laser = 281, mlaser2State = 1;
    int mc3laser = 285, mlaser3State = 1;
    int mc4laser = 289, mlaser4State = 1;
    int mc5laser = 293, mlaser5State = 1;
    int mc6laser = 297, mlaser6State = 1;
    int mlaserToggle = 0;
    int mlaser2Toggle = 0;
    int mlaser3Toggle = 0;
    int mlaser4Toggle = 0;
    int mlaser5Toggle = 0;
    int mlaser6Toggle = 0;
    // .... 
    //colum of lasers.
    int claser = 315;
    int claser2 = 320;
    int claser3 = 325;
    int laser2Toggle = 0;
    int laser3Toggle = 0;
    int laserToggle = 0;
    int laserState = 1;
    int laser2State = 1;
    int laser3State = 1;

    // thorns.

    int cthorns = 350;
    int rthorns = 5;

    //did i take multibullet?
    int mb = 0;

    // Did i take speed run?

    int sr = 0;

    //fired single bullet.
    int b = 0;

    //fired multibullet
    int b2 = 0;

    //Did i take the gun?
    int a = 0;
    //Enemie alive
    int e = 0;
    int e2 = 0;
    int me2 = 0;
    int ct1 = 0;
    int ct2 = 0;
    //dead or alive 
    int h = 0;
    int slow = 0;
    char level = 'A';
    int renemy = 21;
    int renemy2 = 20;
    int cenemy = 250;
    int cenemy2 = 258;

    int GameOver = 0;
    char Lifes = '1';
    char x[26][500];
    cout << "You were a happy mantis shrimp......" << endl;
    char mantisShrimp[13][30] = {
    "          __             ",
    "       .'    `-.         ",
    "      /   O     \\        ",
    "     |     __    |       ",
    "     |    |__|   |       ",
    "     |     __    |       ",
    "     |    |__|   |       ",
    "     \\    '--'   /       ",
    "      `._____.-'          ",
    "        /   \\            ",
    "       /_____|            ",
    "       (     )            ",
    "        `---'             "
    };
    for (int r = 0; r < 13; r++)
    {
        for (int c = 0; c < 30; c++)
        {
            cout << mantisShrimp[r][c];
        }
        cout << endl;
    }
    char choice;
    cout << endl;
    cout << endl;
    cout << "Press S to start | Press ? for story" << endl;
    cin >> choice;
    if (choice == 'S')
    {
        for (;;)
        {
            umove = _getch();
            for (; !_kbhit();)
            {
                map(x, a, h, chero, rhero, sr, mb, c1, slow, umove);
                gravity(x, rhero, chero);
                drawhero(rhero, chero, h, x, s);
                drawenemy1(renemy, cenemy, e, x, ct1);
                moveenemy1(cenemy, a, chero, h, e, rhero, renemy);
                drawenemy2(renemy2, cenemy2, e2, x, ct2);
                moveenemy2(cenemy2, a, chero, h, me2, e, rhero, renemy2);
                drawElevator(x, relevator, celevator);
                eletoggle++;
                if (eletoggle >= 2)
                {
                    eletoggle = 0;
                    moveElevator(direle, relevator, rhero, chero, celevator);
                }
                minilaser(h, x, chero, mclaser, mlaserState, mrlaser, rhero);
                minilaser(h, x, chero, mc2laser, mlaser2State, mrlaser, rhero);
                minilaser(h, x, chero, mc3laser, mlaser3State, mrlaser, rhero);
                minilaser(h, x, chero, mc4laser, mlaser4State, mrlaser, rhero);
                minilaser(h, x, chero, mc5laser, mlaser5State, mrlaser, rhero);
                minilaser(h, x, chero, mc6laser, mlaser6State, mrlaser, rhero);
                mlaserToggle++;
                mlaser2Toggle++;
                mlaser3Toggle++;
                mlaser4Toggle++;
                mlaser5Toggle++;
                mlaser6Toggle++;
                if (mlaserToggle >= 20 || mlaser2Toggle >= 20 || mlaser3Toggle >= 20 || mlaser4Toggle >= 20 || mlaser5Toggle >= 20 || mlaser6Toggle >= 20)
                {
                    mlaserToggle = 0;
                    mlaser2Toggle = 0;
                    mlaser3Toggle = 0;
                    mlaser4Toggle = 0;
                    mlaser5Toggle = 0;
                    mlaser6Toggle = 0;

                    if (mlaserState == 1 || mlaser2State == 1 || mlaser3State == 1 || mlaser4State == 1 || mlaser5State == 1 || mlaser6State == 1)
                    {
                        mlaserState = 0;
                        mlaser2State = 0;
                        mlaser3State = 0;
                        mlaser4State = 0;
                        mlaser5State = 0;
                        mlaser6State = 0;
                    }
                    else
                    {
                        mlaserState = 1;
                        mlaser2State = 1;
                        mlaser3State = 1;
                        mlaser4State = 1;
                        mlaser5State = 1;
                        mlaser6State = 1;
                    }
                }

                laser(h, x, chero, claser, laserState);
                laser(h, x, chero, claser2, laser2State);
                laser(h, x, chero, claser3, laser3State);
                laserToggle++;
                laser2Toggle++;
                laser2Toggle++;
                if (laserToggle >= 20 || laser2Toggle >= 20 || laser3Toggle >= 20)
                {
                    laserToggle = 0;
                    laser2Toggle = 0;
                    laser3Toggle = 0;

                    if (laserState == 1 || laser2State == 1 || laser3State == 1)
                    {
                        laserState = 0;
                        laser2State = 0;
                        laser3State = 0;
                    }
                    else
                    {
                        laserState = 1;
                        laser2State = 1;
                        laser3State = 1;
                    }
                }
                drawthorns(x, cthorns, rthorns);
                movethorns(x, cthorns, chero, h, slow);
                Gameover(GameOver, chero);
                moveBullets(x, gnblt, cenemy, e, cenemy2, e2, renemy, me2, ct1, ct2);
                moveMultiBullets(x, rvblt);
                laserGate(h, x, rvblt, cr, chero, mct);
                screen(colum, chero, x, b, level, a, cenemy, e, cenemy2, e2, me2, GameOver, Score, Lifes, h, claser, b2);

            }

            movehero(rhero, chero, umove, colum, a, h, x, sr, mb, s, gnblt, rvblt);
        }

    }
    else if (choice == '?')
    {
        cout << "Then, one day you got curious of what is up from the sea," << endl;
        cout << "but unfortunately you were kidnapped by a woman " << endl;
        cout << "which later turned out to be a witch o_o" << endl;
        cout << "do you escape | accept your fate? E/F" << endl;
        cout << "___________________" << endl;
        cin >> choice;
        if (choice == 'E')
        {
            system("cls");
            cout << "Well, this wasn't all the truth..." << endl;
            cout << "She wanted to turn you to look like her son" << endl;
            cout << "Who died at a staring contest with a squirrel 0_0" << endl;
            cout << "Now you've grown hands" << endl;
            cout << "can walk, jump, shoot her clones." << endl;
            cout << "Good Luck escaping the witch's room!" << endl;
            cout << "----------------" << endl;
            cout << "Press C to continue" << endl;
            cin >> choice;
            if (choice == 'C')
            {
                system("cls");
                cout << "Press H for Help! | Press S To Start" << endl;
                cin >> choice;
                if (choice == 'H')
                {
                    system("cls");
                    char themace[12][32] = {
    "          ___             ",
    "        <( o )>           ",
    "       --| | |--          ",
    "         /_|_\\            ",
    "        / /_\\ \\           ",
    "       |__   __|           ",
    "          | |              ",
    "         /   \\             ",
    "        /_____|            ",
    "        (     )            ",
    "         `---'             ",
    "       The Mace           "
                    };

                    for (int r = 0; r < 12; r++)
                    {
                        for (int c = 0; c < 32; c++)
                        {
                            cout << themace[r][c];
                        }
                        cout << endl;
                    }
                    cout << endl;
                    cout << "Forged from shattered timelines, The Mace does not simply kill..." << endl;
                    cout << "It sends clones to a different dimension" << endl;
                    cout << "How it works: " << endl;
                    cout << "Its power flares when you strike from the correct position " << endl;
                    cout << "creating a shot that consumes the target. But the fabric of time is sensetive..." << endl;
                    cout << "One flare at a time." << endl;


                    cout << "---------------" << endl;
                    char theshard[16][32] = {
    "                         ",
    "          /              ",
    "         /               ",
    "        /__              ",
    "       |   |              ",
    "       |___|              ",
    "         |                ",
    "         |                ",
    "        / \\              ",
    "       /___\\             ",
    "        |               ",
    "        |               ",
    "        \\               ",
    "         \\               ",
    "          \\               ",
    "     The Shard           "
                    };

                    for (int r = 0; r < 16; r++)
                    {
                        for (int c = 0; c < 32; c++)
                        {
                            cout << theshard[r][c];
                        }
                        cout << endl;
                    }
                    cout << endl;
                    cout << "Forged from cursed crystal, the Shard was not meant to be in here..." << endl;
                    cout << "It breaks curses, not bones." << endl;
                    cout << "How it works: " << endl;
                    cout << "When fired from close range, it splits into two charges." << endl;
                    cout << "striking the source for the curse to break." << endl;
                    cout << "Press C to continue" << endl;
                    cin >> choice;
                    if (choice == 'C')
                    {
                        system("cls");
                        cout << "You are hurt because of all the spells she made on you" << endl;
                        cout << "If anything happens to you,              IT'S GAMEOVER x_x " << endl;
                        for (;;)
                        {
                            umove = _getch();
                            for (; !_kbhit();)
                            {
                                map(x, a, h, chero, rhero, sr, mb, c1, slow, umove);
                                gravity(x, rhero, chero);
                                drawhero(rhero, chero, h, x, s);
                                drawenemy1(renemy, cenemy, e, x, ct1);
                                moveenemy1(cenemy, a, chero, h, e, rhero, renemy);
                                drawenemy2(renemy2, cenemy2, e2, x, ct2);
                                moveenemy2(cenemy2, a, chero, h, me2, e, rhero, renemy2);
                                drawElevator(x, relevator, celevator);
                                moveElevator(direle, relevator, rhero, chero, celevator);
                                minilaser(h, x, chero, mclaser, mlaserState, mrlaser, rhero);
                                minilaser(h, x, chero, mc2laser, mlaser2State, mrlaser, rhero);
                                minilaser(h, x, chero, mc3laser, mlaser3State, mrlaser, rhero);
                                minilaser(h, x, chero, mc4laser, mlaser4State, mrlaser, rhero);
                                minilaser(h, x, chero, mc5laser, mlaser5State, mrlaser, rhero);
                                minilaser(h, x, chero, mc6laser, mlaser6State, mrlaser, rhero);
                                mlaserToggle++;
                                mlaser2Toggle++;
                                mlaser3Toggle++;
                                mlaser4Toggle++;
                                mlaser5Toggle++;
                                mlaser6Toggle++;
                                if (mlaserToggle >= 20 || mlaser2Toggle >= 20 || mlaser3Toggle >= 20 || mlaser4Toggle >= 20 || mlaser5Toggle >= 20 || mlaser6Toggle >= 20)
                                {
                                    mlaserToggle = 0;
                                    mlaser2Toggle = 0;
                                    mlaser3Toggle = 0;
                                    mlaser4Toggle = 0;
                                    mlaser5Toggle = 0;
                                    mlaser6Toggle = 0;

                                    if (mlaserState == 1 || mlaser2State == 1 || mlaser3State == 1 || mlaser4State == 1 || mlaser5State == 1 || mlaser6State == 1)
                                    {
                                        mlaserState = 0;
                                        mlaser2State = 0;
                                        mlaser3State = 0;
                                        mlaser4State = 0;
                                        mlaser5State = 0;
                                        mlaser6State = 0;
                                    }
                                    else
                                    {
                                        mlaserState = 1;
                                        mlaser2State = 1;
                                        mlaser3State = 1;
                                        mlaser4State = 1;
                                        mlaser5State = 1;
                                        mlaser6State = 1;
                                    }
                                }

                                laser(h, x, chero, claser, laserState);
                                laser(h, x, chero, claser2, laser2State);
                                laser(h, x, chero, claser3, laser3State);
                                laserToggle++;
                                laser2Toggle++;
                                laser2Toggle++;
                                if (laserToggle >= 20 || laser2Toggle >= 20 || laser3Toggle >= 20)
                                {
                                    laserToggle = 0;
                                    laser2Toggle = 0;
                                    laser3Toggle = 0;

                                    if (laserState == 1 || laser2State == 1 || laser3State == 1)
                                    {
                                        laserState = 0;
                                        laser2State = 0;
                                        laser3State = 0;
                                    }
                                    else
                                    {
                                        laserState = 1;
                                        laser2State = 1;
                                        laser3State = 1;
                                    }
                                }
                                drawthorns(x, cthorns, rthorns);
                                movethorns(x, cthorns, chero, h, slow);
                                Gameover(GameOver, chero);
                                moveBullets(x, gnblt, cenemy, e, cenemy2, e2, renemy, me2, ct1, ct2);
                                moveMultiBullets(x, rvblt);
                                laserGate(h, x, rvblt, cr, chero, mct);
                                screen(colum, chero, x, b, level, a, cenemy, e, cenemy2, e2, me2, GameOver, Score, Lifes, h, claser, b2);

                            }

                            movehero(rhero, chero, umove, colum, a, h, x, sr, mb, s, gnblt, rvblt);
                        }
                    }
                }
                if (choice == 'S')
                {
                    if (choice == 'C' || choice == 'S')
                    {
                        system("cls");
                        cout << "You are hurt because of all the spells she made on you" << endl;
                        cout << "If anything happens to you,              IT'S GAMEOVER x_x " << endl;
                        for (;;)
                        {
                            umove = _getch();
                            for (; !_kbhit();)
                            {
                                map(x, a, h, chero, rhero, sr, mb, c1, slow, umove);
                                gravity(x, rhero, chero);
                                drawhero(rhero, chero, h, x, s);
                                drawenemy1(renemy, cenemy, e, x, ct1);
                                moveenemy1(cenemy, a, chero, h, e, rhero, renemy);
                                drawenemy2(renemy2, cenemy2, e2, x, ct2);
                                moveenemy2(cenemy2, a, chero, h, me2, e, rhero, renemy2);
                                drawElevator(x, relevator, celevator);
                                moveElevator(direle, relevator, rhero, chero, celevator);
                                minilaser(h, x, chero, mclaser, mlaserState, mrlaser, rhero);
                                minilaser(h, x, chero, mc2laser, mlaser2State, mrlaser, rhero);
                                minilaser(h, x, chero, mc3laser, mlaser3State, mrlaser, rhero);
                                minilaser(h, x, chero, mc4laser, mlaser4State, mrlaser, rhero);
                                minilaser(h, x, chero, mc5laser, mlaser5State, mrlaser, rhero);
                                minilaser(h, x, chero, mc6laser, mlaser6State, mrlaser, rhero);
                                mlaserToggle++;
                                mlaser2Toggle++;
                                mlaser3Toggle++;
                                mlaser4Toggle++;
                                mlaser5Toggle++;
                                mlaser6Toggle++;
                                if (mlaserToggle >= 20 || mlaser2Toggle >= 20 || mlaser3Toggle >= 20 || mlaser4Toggle >= 20 || mlaser5Toggle >= 20 || mlaser6Toggle >= 20)
                                {
                                    mlaserToggle = 0;
                                    mlaser2Toggle = 0;
                                    mlaser3Toggle = 0;
                                    mlaser4Toggle = 0;
                                    mlaser5Toggle = 0;
                                    mlaser6Toggle = 0;

                                    if (mlaserState == 1 || mlaser2State == 1 || mlaser3State == 1 || mlaser4State == 1 || mlaser5State == 1 || mlaser6State == 1)
                                    {
                                        mlaserState = 0;
                                        mlaser2State = 0;
                                        mlaser3State = 0;
                                        mlaser4State = 0;
                                        mlaser5State = 0;
                                        mlaser6State = 0;
                                    }
                                    else
                                    {
                                        mlaserState = 1;
                                        mlaser2State = 1;
                                        mlaser3State = 1;
                                        mlaser4State = 1;
                                        mlaser5State = 1;
                                        mlaser6State = 1;
                                    }
                                }

                                laser(h, x, chero, claser, laserState);
                                laser(h, x, chero, claser2, laser2State);
                                laser(h, x, chero, claser3, laser3State);
                                laserToggle++;
                                laser2Toggle++;
                                laser2Toggle++;
                                if (laserToggle >= 20 || laser2Toggle >= 20 || laser3Toggle >= 20)
                                {
                                    laserToggle = 0;
                                    laser2Toggle = 0;
                                    laser3Toggle = 0;

                                    if (laserState == 1 || laser2State == 1 || laser3State == 1)
                                    {
                                        laserState = 0;
                                        laser2State = 0;
                                        laser3State = 0;
                                    }
                                    else
                                    {
                                        laserState = 1;
                                        laser2State = 1;
                                        laser3State = 1;
                                    }
                                }
                                drawthorns(x, cthorns, rthorns);
                                movethorns(x, cthorns, chero, h, slow);
                                Gameover(GameOver, chero);
                                moveBullets(x, gnblt, cenemy, e, cenemy2, e2, renemy, me2, ct1, ct2);
                                moveMultiBullets(x, rvblt);
                                laserGate(h, x, rvblt, cr, chero, mct);
                                screen(colum, chero, x, b, level, a, cenemy, e, cenemy2, e2, me2, GameOver, Score, Lifes, h, claser, b2);

                            }

                            movehero(rhero, chero, umove, colum, a, h, x, sr, mb, s, gnblt, rvblt);
                        }
                    }
                }
            }

        }
        else if (choice == 'F')
        {
            system("cls");
            string witchWithShrimp[14] = {
          "       /\\    ",
            "      /__\\   ",
            "     ( QQ )  ",
            "     |/\\/|   ",
            "     _||_    ",
            "    /_____\\   ",
            "   (      )  ",
            "  /|      |\\ ",
            " /_|  u   |_\\ you in her stomach now -_-",
            "   |      |  ",
            "   |______|  ",
            "  /_|____|_\\ ",
            "    ||  ||   ",
            "    []  []   "
            };
            cout << endl;
            cout << endl;
            cout << endl;
            for (int i = 0; i < 14; ++i) {
                cout << witchWithShrimp[i] << endl;
            }
        }
    }

}