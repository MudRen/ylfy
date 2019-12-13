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
                return notify_fail("��... ���������?\n");
	if (ob==me) return notify_fail("������... ���ܰ��Լ���������\n");
	if (environment(ob)==environment(me))	return notify_fail(ob->name(1)+"�Ѿ���������ˡ�\n");
	pos = environment(ob)->query("short");
	// moving
/*
      if (userp(ob) && wiz_level(me) < wiz_level("(arch)") )
      return notify_fail("������ô��\n");
*/
        tell_room(environment(ob),"��������һֻ�ʷʵĴ��ְ�"+
	(string)ob->query("name")+"ץ������, Ȼ�᲻����.\n", ob);
        tell_object(ob,"һֻ���ְ���ץ������, ����ǰһ���....\n");
	ob->move(environment(me));
        tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ.\n");
	tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
	"����Ū������.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ\n",({me,ob}));
	if(!wizardp(ob))
	message("sys",HIY"�������ء�: "+me->query("name")+"("+me->query("id")+")"+"��"+ob->query("name")+"("+ob->query("id")+")��"+pos+"ץ����"+environment(me)->query("short")+"��\n"NOR,users());
	// ok ..
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : summon <ĳ��>
��ָ������㽫ĳ��ץ������ǰ��
HELP
    );
    return 1;
}
