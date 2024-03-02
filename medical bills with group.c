/*This programme is written for supermarket billing system */

/*sample input:2 2 0 5 7 5*/

#include <stdio.h>
#include <conio.h>
int main()
{
  struct d
  {
    char nm[50];
    int pr;
  };

  int i, j, choice, np, qt, sum = 0, tot;
  char ch;

  struct d arr_d[43] = {
      /*cough 0-6*/
      {"ARISTOZYME DROP(1)", 40},
      {"HATRIC3 SYP(2)", 50},
      {"MEFTAL-FORTE TAB(10)", 20},
      {"TUSQ-DX TAB(2)", 10},
      {"ELECTRIC POWDER (250 gm) ", 280},
      {"ENERZAL ORANGE (250 gm)", 75},
      {"PONDS (50 gm)", 30},

      /*NICIP 7-12*/
      {"COSVAT-GM(1)", 390},
      {"SUMAN DROP ADULT(100ml)", 223},
      {"Honey(250 gm)", 77},
      {"table(1 unit)", 9},
      {"deshav-egg(1 unit)", 5},
      {"ATEN 50 TAB(1 unit)", 12},

      /*GENERAL PRODUCT 13-22*/
      {"SORBTRATE TAB(10)", 151},
      {"NAPRO VIT CAP(1)", 16},
      {"MET XL12.5 TAB(10)", 39},
      {"MET XL 25 TAB(10)", 75},
      {"Avacado(250 gm)", 65},
      {"PineA POWDER(500)", 35},
      {"Kivifruit(1 piece)", 12},
      {"Strawberry CONDOM(2)", 150},
      {"CLAVAM BID SYP(10)", 60},
      {"CLAVAM-625(50)", 30},

      /*TAB 23-29*/
      {"PAN 40 TAB(50)", 450},
      {"SUMOCOLD TAB(2)", 10},
      {"TAXIM 1GM INJ(16 ml)", 40},
      {"TAXIM-250 INJ(20 ml)", 55},
      {"TAXIM -500G INJ(21 ml)", 99},
      {"A TO Z NS SYP(1-packet)", 34},
      {"XONE INJ 1GM(21 ml)", 179},

      /*SYP 30-35*/
      {"MONOCEF 1GM (1)", 10},
      {"AMBRODIL SYP(10)", 1000},
      {"SINARIST SYP(55)", 100},
      {"MEFTAL-FORTE TAB(30-pack)", 100},
      {"BETT VACCINE INJ(300ml)", 330},
      {"SANITIZER (300ml-can)", 309},

      /*TABLETS 36-42 */

      {"Toothbrush", 40},
      {"Toothpaste(100gm)", 30},
      {"Everyouth facewash(50gm)", 39},
      {"Listerine(250 ml)", 125},
      {"KESH KING Oil(100ml)", 37},
      {"Patanjali Soap(125 gm)", 25},
      {"Patanjali Kesh kanti(200ml)", 75}}; /*struct initialization done*/
// clrscr();  for turbo c
begin:
  printf("1.To watch available products\n");
  printf("2.To make bill\n");
  printf("3.To exit\n");
  scanf("%d", &choice);

  /*To Watch products available*/
  if (choice == 1)
  {
    printf("CODE \tPRODUCT\tPRICE");
    for (i = 0; i <= 42; i++)
    {
      printf("%d\t%s\t%d\n", i, arr_d[i].nm, arr_d[i].pr);
    }
    printf("b.To go back");
    scanf("\n%c", &ch);
    if (ch == 'b')
    {
      goto begin;
    }
  }
  /*To create bill*/
  else if (choice == 2)
  {
    printf("How many products purchased ?");
    scanf("%d", &np);
    printf("\nenter required data\n");
    printf("\n\nCODE\t Product\t \tQt \n");
    for (j = 1; j <= np; j++)
    {
      scanf("\n%d", &i);
      printf("\t%s\t", arr_d[i].nm);
      scanf("\t%d", &qt);
      sum += (arr_d[i].pr) * qt;
      tot = sum;
    }

    printf("\n\n");
    printf("\n**________BILL________**");
    printf("\n Total=%d Rs", sum);
    printf("\n GST=%f Rs", sum * 0.05);
    /*GOODS AND SRVICES TAX */
    if (sum >= 1000)
    {
      printf("\nDiscount=%f", sum * 0.15);
      printf("\nGrand total=%f",
             sum + sum * (0.05 - 0.15));
    }
    else
    {
      printf("\nGrand total=%f",
             sum + sum * 0.15);
    }
    printf("\n\n\t\tTHANKS FOR VISITING");
  }

  else if (choice == 3)
  {
    goto end;
  }

end:
  //  getch();for turbo c
  return 0;
}
