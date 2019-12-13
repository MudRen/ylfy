// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
inherit F_CLEAN_UP;
string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"����Ȼ��$n��������ش�$P�����⡣\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n",
	"$n�����۾�����$N����ô�򵥵�����ҲҪ����\n",
});
int main(object me, string arg)
{
	mapping ask_msgs;
	string dest, topic, msg, *asks;
	object ob;
	int ask;
	seteuid(getuid());
	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");
	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");
	//if ( me->is_busy() ) return notify_fail("����һ��������û����ɡ�\n");
	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}
	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
			me, ob);
		return 1;
	}
	//me->start_busy(random(3));
	// �г����п�ѯ�ʵ���Ϣ
	ask = 0;
	if ( mapp(ask_msgs=ob->query("inquiry")) 
		&& sizeof(ask_msgs) > 0 
		&& topic == "all" )
	{
		asks = keys(ask_msgs);
		if ( sizeof(asks) > 0 )
		{
			msg = HIW"������� "HIG+ob->name(1)+HIW" ������С����Ϣ���� "HIR+sizeof(asks)+HIW" �����������£�\n"HIY;
			for ( int i=0; i<sizeof(asks); i++ )
			{
				msg += "��"+chinese_number(i+1)+"����"HIG+asks[i]+"\n"HIY;
			}
			tell_object(me, msg);
			ask = 1;
		}
	}
	if( msg = ob->query("inquiry/" + topic) ) 
	{
		if( stringp(msg) ) 
		{
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	} 
	else if ( !ask )
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	return 1;
}
int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>
���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
   );
   return 1;
}
