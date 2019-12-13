

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int i;
   
   if( !arg ) return notify_fail("你要替自己取什么绰号？\n");
   
   if( arg=="none" ) {
   me->delete("nickname");
   return 1;
   }

if(!wizardp(me)&&(i = strlen(arg)) > 30 )       	
     return notify_fail("你的绰号太长了，想一个短一点的、响亮一点的。\n");

   while(i--) {
                  if( arg[i]<' ' ) {
                          return notify_fail("对不起，你的头衔不能用控制字元。\n");
                  }
          }

   arg = replace_string(arg, "$BLK$", BLK);
   arg = replace_string(arg, "$RED$", RED);
   arg = replace_string(arg, "$GRN$", GRN);
   arg = replace_string(arg, "$YEL$", YEL);
   arg = replace_string(arg, "$BLU$", BLU);
   arg = replace_string(arg, "$MAG$", MAG);
   arg = replace_string(arg, "$CYN$", CYN);
   arg = replace_string(arg, "$WHT$", WHT);
   arg = replace_string(arg, "$HIR$", HIR);
   arg = replace_string(arg, "$HIG$", HIG);
   arg = replace_string(arg, "$HIY$", HIY);
   arg = replace_string(arg, "$HIB$", HIB);
   arg = replace_string(arg, "$HIM$", HIM);
   arg = replace_string(arg, "$HIC$", HIC);
   arg = replace_string(arg, "$HIW$", HIW);
   arg = replace_string(arg, "$NOR$", NOR);

   me->set("nickname", arg + NOR);
   write("Ok.\n");
   return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : nick <外号>|none
 
这个指令可以让你为自己取一个响亮的名号或头衔，nick none 为删除。
你如果希望在绰号中使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

HELP
"$BLK$ - "BLK"黑色"NOR"	        $NOR$ - 恢复正常颜色\n"
"$RED$ - "RED"红色"NOR"	        $HIR$ - "HIR"亮红色\n"NOR
"$GRN$ - "GRN"绿色"NOR"	        $HIG$ - "HIG"亮绿色\n"NOR
"$YEL$ - "YEL"土黄色"NOR"       $HIY$ - "HIY"黄色\n"NOR
"$BLU$ - "BLU"深蓝色"NOR"       $HIB$ - "HIB"蓝色\n"NOR
"$MAG$ - "MAG"浅紫色"NOR"       $HIM$ - "HIM"粉红色\n"NOR
"$CYN$ - "CYN"蓝绿色"NOR"       $HIC$ - "HIC"天青色\n"NOR
"$WHT$ - 浅灰色	　	$HIW$ - "HIW"白色\n"NOR
@HELP 

其中系统自动会在字串尾端加一个 $NOR$。
HELP
);
        return 1;
}
