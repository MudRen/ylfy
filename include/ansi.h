//	File	:  /include/ansi.h
//	The standard set of ANSI codes for mudlib use.
#ifndef __ANSI_H__
#define __ANSI_H__ 
 
#define ESC     ""
#define CSI	ESC + "["
#define BEL	ESC + "[s"
                /*  Foreground Colors  */
 
#define BLK     ESC+"[30m"          /* Black    */
#define RED     ESC+"[31m"          /* Red      */
#define GRN     ESC+"[32m"          /* Green    */
#define YEL     ESC+"[33m"          /* Yellow   */
#define BLU     ESC+"[34m"          /* Blue     */
#define MAG     ESC+"[35m"          /* Magenta  */
#define CYN     ESC+"[36m"          /* Cyan     */
#define WHT     ESC+"[37m"          /* White    */
 
                /*   Hi Intensity Foreground Colors   */
                
#define HIK     ESC+"[1;30m"	    /* Black    */ 
#define HIR     ESC+"[1;31m"        /* Red      */
#define HIG     ESC+"[1;32m"        /* Green    */
#define HIY     ESC+"[1;33m"        /* Yellow   */
#define HIB     ESC+"[1;34m"        /* Blue     */
#define HIM     ESC+"[1;35m"        /* Magenta  */
#define HIC     ESC+"[1;36m"        /* Cyan     */
#define HIW     ESC+"[1;37m"        /* White    */
#define HBK     ESC+"[1;30m"        /* Gray     */

                /* High Intensity Background Colors  */

#define HBRED   ESC+"[41;1m"        /* Red      */
#define HBGRN   ESC+"[42;1m"        /* Green    */
#define HBYEL   ESC+"[43;1m"        /* Yellow   */
#define HBBLU   ESC+"[44;1m"        /* Blue     */
#define HBMAG   ESC+"[45;1m"        /* Magenta  */
#define HBCYN   ESC+"[46;1m"        /* Cyan     */
#define HBWHT   ESC+"[47;1m"        /* White    */
 
                /*  Background Colors  */
 
#define BBLK    ESC+"[40m"          /* Black    */
#define BRED    ESC+"[41m"          /* Red      */
#define BGRN    ESC+"[42m"          /* Green    */
#define BYEL    ESC+"[43m"          /* Yellow   */
#define BBLU    ESC+"[44m"          /* Blue     */
#define BMAG    ESC+"[45m"          /* Magenta  */
#define BCYN    ESC+"[46m"          /* Cyan     */
#define BWHT    ESC+"[47m"          /* White    */

#define NOR     ESC+"[2;37;0m"      /* Puts everything back to normal */
 
/*  Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
 
#define BOLD    ESC+"[1m"           /* Turn on bold mode */
#define CLR     ESC+"[2J"           /* Clear the screen  */
#define HOME    ESC+"[H"            /* Send cursor to home position */
#define REF     CLR+HOME            /* Clear screen and home cursor */
#define BIGTOP  ESC+"#3"            /* Dbl height characters, top half */
#define BIGBOT  ESC+"#4"            /* Dbl height characters, bottem half */
#define SAVEC   ESC+"[s"            /* Save cursor position */
#define REST    ESC+"[u"            /* Restore cursor to saved position */
//#define REVINDEX ESC+"M           /* Scroll screen in opposite direction */
#define SINGW   ESC+"#5"            /* Normal, single-width characters */
#define DBL     ESC+"#6"            /* Creates double-width characters */
#define FRTOP   ESC+"[2;25r"        /* Freeze top line */
#define FRBOT   ESC+"[1;24r"        /* Freeze bottom line */
#define UNFR    ESC+"[r"            /* Unfreeze top and bottom lines */
#define BLINK   ESC+"[5m"           /* Initialize blink mode */
#define U       ESC+"[4m"           /* Initialize underscore mode */
#define REV     ESC+"[7m"           /* Turns reverse video mode on */
#define HIREV   ESC+"[1,7m"         /* Hi intensity reverse video  */
 
#define FLASH   ESC+"[5m"           // flash
                /*关于行控制 */
                /*1.移动 */
#define TOTOP(x)        (ESC+"["+x+"A")         /*向上跳转x行*/
#define TOBOT(x)        (ESC+"["+x+"B")         /*向下跳转x行*/
                                                /*当 游标已经在萤幕的最下一列时, 此一命令没有作用*/
#define TORIGHT(x)      (ESC+"["+x+"C")         /*向右移动x行*/
                                                /*当游标已经在萤幕的最右一栏时, 此一命令没有作用。*/
#define TOLEFT(x)       (ESC+"["+x+"D")         /*向左移动x行*/
                                                /*当游标已经在萤幕的最左一栏时, 此一命令没有作用。*/
#define TOPOINT(x,y)    (ESC+"["+x+";"+y+"f")   /*移动到点坐标为(x,y) x:行，y:列*/
#define TOPOINTA(x,y)   (ESC+"["+x+";"+y+"H")
                /*2.清除屏幕*/
#define CLR_LINE        ESC+"[K"                /*清除到行尾*/
#define SETDISPLAY(x,y) (ESC+"["+x+";"+y+"f") 
// #define DELLINE      ESC+"[K" 
                /*3.冻结屏幕指定行*/
/* 冻结屏幕指定行，x 是行号，从上往下数，分辨率为 800 x 600，y = 35，
 * 分辨率为 1024 x 768，y = 40。  */              
#define FRELINE(x,y)    (ESC+"["+x+";"+y+"r")

#define CUP(n)		sprintf(ESC+"[%dA",n)	/* Cursor Up n lines */
#define CDOWN(n)	sprintf(ESC+"[%dB",n)	/* Cursor Down n lines */
#define CFW(n)		sprinff(ESC+"[%dC",n)	/* Cursor Forward n characters */
#define CBK(n)		sprintf(ESC+"[%dD",n)	/* Cursor Backward n characters */
#define DELLINE		sprintf(ESC+"[K\n"+CUP(1))
			                        /* Erase to end of line and move Cursor to home of the line */
#define CMOVE(y,x)	sprintf(ESC+"[%d;%dH",y,x)	
                                                /* Move Cursor to (y,x) position */
#define BEEP ""

#endif