// ת����ɫ
#ifndef __F__COLOR__C__
#define __F__COLOR__C__

string clean_color(string arg)
{
	   if(!arg)
		   return "";

	   arg = replace_string(arg, BLK, "");
       arg = replace_string(arg, RED, "");
       arg = replace_string(arg, GRN, "");
       arg = replace_string(arg, YEL, "");
       arg = replace_string(arg, BLU, "");
       arg = replace_string(arg, MAG, "");
       arg = replace_string(arg, CYN, "");
       arg = replace_string(arg, WHT, "");
       arg = replace_string(arg, HIR, "");
       arg = replace_string(arg, HIG, "");
       arg = replace_string(arg, HIY, "");
       arg = replace_string(arg, HIB, "");
       arg = replace_string(arg, HIM, "");
       arg = replace_string(arg, HIC, "");
       arg = replace_string(arg, HIW, "");
       arg = replace_string(arg, NOR, "");
       arg = replace_string(arg, BLINK,"");
	   return arg;

}
#endif
