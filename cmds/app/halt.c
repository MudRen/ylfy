// halt.c
#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	if (!arg){
	if( !me->is_fighting() )
		return notify_fail("�����ڲ�û����ս����\n");
	me->remove_all_killer(1);
	message_vision("$N����ʦ������ֹͣ���ⳡ�򶷡�\n", me);
	}else{
		if (ob=present(arg, environment(me))){
			if (!ob->is_character() || ob->is_corpse())
				return notify_fail(ob->name()+"Ҳ��ս������Ц���ҵĴ�����\n");
			if( !ob->is_fighting() )
				return notify_fail(ob->name()+"���ڲ�û����ս����\n");
			ob->remove_all_killer(1);
			message_vision("$N����ʦ������ֹͣ��$n���ⳡ�򶷡�\n", me,ob);
		}
	}
	write("Ok.\n");
	return 1;
}
int help(object me)
{
   write(@HELP
ָ���ʽ: halt <ĳ��>
����ֹͣ��������(��ĳ��)�йص�ս����
HELP
   );
   return 1;
}
