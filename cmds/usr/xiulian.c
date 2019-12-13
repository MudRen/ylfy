// �������� By ������(Wenwu) On 2006��1��21��

#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("channel_id", "��������");
}

int main(object me, string arg)
{
	object ob;
	string name;

	if ( !interactive(me) ) return 0;
	// �ǻ�Ա������������
	if ( !stringp(me->query("xy_huiyuan")) || !sscanf(me->query("xy_huiyuan"), "%*s��%*s��%*s��") )
		return notify_fail(HIY"ֻ�л�Ա�������߱չ�������\n"NOR);
	/*if ( !me->query("xyhy_type") )
		return notify_fail(HIR"��ѻ�Ա�޷�ʹ�������������ܡ�\n"NOR);*/
	if ( !wizardp(me) && me->query_condition("killer") ) 
		return notify_fail(HIR"��Ŀǰ�����ٸ�����ͨ�����޷����ıչ�������\n"NOR);

	ob = me->query_temp("link_ob");

	if ( me->query("biguan_is_online", 1) < 1800 && me->query("xyhy_type") != 2 )
		return notify_fail(HIR"��ʣ�����������ʱ�䲻��һСʱ����ʱ�޷����߱չء�\n"HIY"�������ھ��뿪��Ϸ����ʹ��ָ��[quit]�˳���Ϸ��\n"NOR);

	if ( file_size(DATA_DIR + "biguan/" + me->query("id") + __SAVE_EXTENSION__) == -1 
		&& file_size(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__) == -1 )
		return notify_fail(HIY"�㻹û������ָ�����ʹ��ָ��"HIC" setcmds �� setchufa "HIY"���á�\n"NOR);

	if ( me->query("block") ) return notify_fail(HIR"�ؼ��и�Ȩ���ѱ����ᡣ\n"NOR);

	if ( ob )
	{
		// Ԫ�������
		if ( ob->is_character() )
			return notify_fail(HIY"��������Ԫ������У��޷����߱չ�������\n"NOR);

		//exec(ob, me);
		ob->save();
		write(HIC"�㿪ʼ�չ���������ʱ�뿪��Ϸ������\n"NOR);
		destruct(ob);
	}
	else
	{
		ob = new(LOGIN_OB);
		ob->set("id", me->query("id"));

		// ����������
		if ( !ob->restore() )
		{
			write( HIR"��ĵ����������⣬����ϵ��ʦ����\n"NOR);
			destruct(ob);
        	return 0;
		}

		//exec(ob, me);
		write(HIC"�㿪ʼ�չ���������ʱ�뿪��Ϸ������\n"NOR);
		destruct(ob);
	}

	me->set("lixian/biguan",1);
	me->delete_temp("do_xiulian_num");

	if ( !wizardp(me) )
	{
		if ( sscanf(base_name(environment(me)), "/u/%*s") 
			|| sscanf(base_name(environment(me)), "/d/automap/%*s") 
			|| sscanf(base_name(environment(me)), "/d/migong/%*s") 
			|| environment(me)->query("no_login")
			|| clonep(environment(me)) 
			|| virtualp(environment(me)) )
		{
			me->delete("startroom");
		}
		else
			me->set("startroom", base_name(environment(me)));
		me->set("quit_time",time());
	}
	else me->set("startroom", base_name(environment(me)));
	
	me->delete("exp_jiacheng");
	me->save();
	remove_interactive(me);
	BIGUAN_D->add_bg_user(me);

	// ������
	if ( stringp(name = me->query_temp("xyzx_team/name")) )
			TEAMD->del_team_member(me);

	message("system", HIW + me->name(1) + "��ʼ����������\n"NOR, environment(me));
	message("chat", HIY"������ˮ�¡���" + HIW"��˵ "HIC + me->query("name") + HIW" ��ʼ���߱չ�����,��Ȼ����������ͼ�������������\n"NOR, users() );

	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��xiulian
   ���ָ������������߼ƻ����������ߺ�����������Ȩת������ϵͳ��
ϵͳ�ᰴ����ļƻ�Ҫ�����ѭ��ִ��ָ�������Ҫ����Ǳ�ܵģ�ÿִ��
һ��ָ�������һ��Ǳ�ܣ���Ȼ�������ע���Ա�Ļ��Ͳ����˷���ЩǱ��
�ˡ�������α�����Ҫ��ָ�������ο� help setcmds
TEXT
	);
	return 1;
}