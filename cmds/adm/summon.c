// summon command..
inherit F_CLEAN_UP;
object find_player(string target)
{
      int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string str)
{
	object ob;
	string pos;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) ob=find_player(str);
	if (!ob) ob=find_living(str);
     if (!ob||(!me->visible(ob)))
                return notify_fail("咦... 有这个人吗?\n");
	if (ob==me) return notify_fail("哈哈哈... 你能把自己提起来吗？\n");
	if (environment(ob)==environment(me))	return notify_fail(ob->name(1)+"已经在你身边了。\n");
	pos = environment(ob)->query("short");
	// moving
/*
      if (userp(ob) && wiz_level(me) < wiz_level("(arch)") )
      return notify_fail("想作弊么？\n");
*/
        tell_room(environment(ob),"天空中伸出一只肥肥的大手把"+
	(string)ob->query("name")+"抓了起来, 然後不见了.\n", ob);
        tell_object(ob,"一只贼手把你抓了起来, 你眼前一阵黑....\n");
	ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
	"把你弄过来的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出现"+
	"在你眼前\n",({me,ob}));
	if(!wizardp(ob))
	message("sys",HIY"〖管理监控〗: "+me->query("name")+"("+me->query("id")+")"+"将"+ob->query("name")+"("+ob->query("id")+")从"+pos+"抓到了"+environment(me)->query("short")+"。\n"NOR,users());
	// ok ..
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : summon <某人>
此指令可让你将某人抓到你面前。
HELP
    );
    return 1;
}
