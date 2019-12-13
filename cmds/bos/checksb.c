// checksb.c
// 2003.7.24 lisa
// 1.00 检查人物身标
inherit F_CLEAN_UP;
int main(object me, string arg)
{
object ob;
if (!arg)   return notify_fail("你要检查谁的身份标识?\n");
ob=FINGER_D->acquire_login_ob(arg);
if(!objectp(ob))   return notify_fail("没有这位玩家。\n");	
//   if( me!=this_player(1) )        	
write("请输入欲验证的身份标识∶");
input_to("get_biaoshi", 1, ob );
return 1;
}
private void get_biaoshi(string biaoshi, object ob)
{
string old_biaoshi;
write("\n");
old_biaoshi=ob->query("biaoshiold");
if( crypt(biaoshi, old_biaoshi)!=old_biaoshi ) {
write("身份标识错误。\n");
return;
}
write("身份标识正确。\n");
}
int help(object me)
{
write(@HELP
指令格式 : checksb <玩家id>

这个指令可以检查玩家的身份标识。

HELP
);
return 1;
}
