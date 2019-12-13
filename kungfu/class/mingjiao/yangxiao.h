// YangXiao.h
// pal 1997.05.10

#include <ansi.h>

string* names = ({
	"chengguan luohan",
	"chengzhi luohan",
	"chengming luohan",
	"chengjing luohan",
	"chengjian luohan",
	"chengxing luohan",
	"chengji luohan",
	"chengmie luohan",
	"chenghe luohan",
});

string ask_me()
{
	mapping fam, my_fam, skl; 
        object fighter, me, room, monk;
	string *sname;
	int i,j;

	fighter = this_player();
	me = this_object();
	my_fam  = me->query("family");

	skl = fighter->query_skills();
	sname  = keys(skl);

	for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 80) 
		return RANK_D->query_respect(fighter) + 
                "���������������ʸ񴳹���ʥ����";
	}

	if( fighter->query("luohan_winner") )
		return RANK_D->query_respect(fighter) + 
                "��Ȼ��������ʥ���󣬿ɲ�Ҫ�����п������Ц��";

	if ( mapp(fam = fighter->query("family")) 
        && fam["family_name"] == "����"
	&& fam["generation"] != (my_fam["generation"] + 2))
		return RANK_D->query_respect(fighter) + 
                "ְλ���ϣ������ʸ񴳹���ʥ����";

        if ( (int)fighter->query("guilty") > 0 )
		return RANK_D->query_respect(fighter) + 
                "���۷����䣬�������������׼���㴳����ʥ����";

	if ( me->query("assigned_fighter") )
		return RANK_D->query_respect(fighter) + 
                "��������������ս����ʥ�������һ��ʱ�������ɡ�";

	fighter->set_temp("xuanku-asked", 1);

        say("\n����˵�����ðɣ������ټ��޺��ó������ڶ����䳡���ϣ����Ժ����������䳡�ϵ��㡣\n");

	me->set("assigned_fighter", fighter->query("id")); 		
	
	if( !fighter->query_temp("xuannan-asked") )
        say("\n�����ֵ���������ȥ��֪�����÷���ʹ�����������м����������޺��������䳡���ϡ�\n");

        message_vision("\n���������뿪��\n\n", fighter);

        for(j=1; j<10; j++) 
	{
                if(!( room = find_object("/d/shaolin/luohan" + j)) )
                room = load_object("/d/shaolin/luohan" + j);
                
  		me->move(room);
                
		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/shaolin/luohan5");
                        message_vision("\n�������˹�����\n\n", fighter);
                        return "���ǶԲ����޺��������˲��ڣ��޷����й���ʥ����\n";
		}

                message("vision", "\n�������˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);

                monk->move("/d/shaolin/wuchang2");
                message("vision", monk->query("name") + "�޺����˵�ͷ���첽���˳�ȥ��\n", room, monk);
	}
	
        me->move("/d/shaolin/wuchang");

        call_out("waiting", 1, me);

	return "�ã���Ҷ������ˡ�\n";
}

int waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 300 )
	{
                say( "����˵�����������������ˣ����ǻ�ȥ�գ�\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	else if( !present("xuannan dashi", environment(me)) || !fighter->query_temp("xuannan-asked") )
	{
		if( random(10) == 0 ) 
                say("\n����˵����" + RANK_D->query_respect(fighter) + "ȥ���˷���ʹû�У� ���������ڸõ��˰գ�\n");

		wait_time++;
		call_out("waiting", 1, me);
	}
	else 	call_out("preparing", 1, me, fighter);

	return 1;
}

int preparing(object me, object fighter)
{
	object monk, room;

	if(!( room = find_object("/d/shaolin/wuchang2")) )
	room = load_object("/d/shaolin/wuchang2");
	monk = present("mu ren", room);
	monk->move("/d/shaolin/houdian");

	if(!( room = find_object("/d/shaolin/wuchang1")) )
	room = load_object("/d/shaolin/wuchang1");
	monk = present("mu ren", room);
	monk->move("/d/shaolin/houdian");

	if(!( room = find_object("/d/shaolin/wuchang")) )
	room = load_object("/d/shaolin/wuchang");

	monk = present("daojue chanshi", room);
        message("vision", "���и�������ʦ��������˵�˼��䡣\n", room, monk );
	monk->move("/d/shaolin/houdian");
	message("vision", monk->query("name") + "��ʦ���˵�ͷ���첽�����뿪��\n", room);

        message("vision", HIY "\n���д���������������ʥ�����Χ��\n" NOR, room);
	message("vision", "\nֻ����������ɳɳ�ĽŲ���������ʮ��λ�޺��Ǹ���������ɱ��\n"
		"����ֿ�ȭ�����ֱֳ�����������Χ����������ס��ͨ·��\n\n", room);
	room->delete("exits");

        say( "�����ֵ���׼��������ʥ���󼴿̷�����\n\n");

	fighter->delete_temp("xuanku-asked");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

	call_out("fighting",  10, me, fighter, 0);

	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;

	if(!( room1 = find_object("/d/shaolin/wuchang2")) )
	room1 = load_object("/d/shaolin/wuchang2");

	if(!( room2 = find_object("/d/shaolin/wuchang")) )
	room2 = load_object("/d/shaolin/wuchang");

//	message_vision(HIY "xuanku's count = " + count + "\n" NOR, fighter);

	if( count <= 8 ) {
                message("vision", "\n����ʥ�����ٵ���ת�ţ�һ���������ս���\n" NOR, room2);

		monk1 = present(names[count], room1);
		monk1->move(room2);
	}
		
	if( count >= 1 && count <= 9 ) {
		monk2 = present(names[count-1], room2);
		monk2->move(room1);
	}

	if( !find_player(me->query("assigned_fighter")) ||
	!living(fighter) || fighter->query("qi") <= 1 )
	{
		if( objectp(present(me->query("assigned_fighter"), environment(me)) )) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);

                say( "����ҡ��ҡͷ��˵�����벻�� ... ����\n\n");
		command("sigh");
		call_out("do_back", 5, me );
	}
	else if( count >= 9 )
	{
		if( (int)fighter->query_temp("beat_count") >= 18 )	
			call_out("do_recruit", 5, me, fighter);
		else
			call_out("do_back", 5, me );
	}
	else
	{
		count++;
		call_out("fighting", 2, me, fighter, count);
	}
 
	return 1;
}

int do_recruit(object me, object fighter)
{
	mapping ft_fam;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	fighter->add("combat_exp", 7500);
	fighter->set("luohan_winner", 1);

        if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "����")
	{
		command("bow");
                say("����˵����" + RANK_D->query_respect(fighter) + "�˷����󣬵��Ա������д������棬�ٳ߸�ͷ������һ�������оʹ˱����\n");
		call_out("do_back", 5, me );
	}
	else
	{
                say("\n����˵������ϲ�㴳���˹���ʥ���� �����д˵Ƚܳ����ӣ���ʱ�ص�Ϊ���ַ�һ��ʣ�\n");
		call_out("do_back", 30, me );
	}

		
	return 1;
}

int do_back(object me)
{
        object monk, room1, room2;
	int i;

        message("vision", "\n���л��˻��֣� �޺��ó������漴����뿪���䳡��\n", environment(me) );
	
        if(!( room1 = find_object("/d/shaolin/wuchang")) )
        room1 = load_object("/d/shaolin/wuchang");

        if(!( room2 = find_object("/d/shaolin/houdian")) )
        room2 = load_object("/d/shaolin/houdian");

        monk = present("daojue chanshi", room2);
	monk->move("/d/shaolin/wuchang");
        monk = present("mu ren", room2);
	monk->move("/d/shaolin/wuchang2");
        monk = present("mu ren", room2);
	monk->move("/d/shaolin/wuchang1");

        if(!( room1 = find_object("/d/shaolin/wuchang2")) )
        room1 = load_object("/d/shaolin/wuchang2");

	for(i=1; i<10; i++) 
	{
                if(!( room2 = find_object("/d/shaolin/luohan" + i)) )
                room2 = load_object("/d/shaolin/luohan" + i);

                if( objectp( monk = present(names[i-1], room1) ));
	                monk->move(room2);
	}

        me->delete("assigned_fighter");
	
	me->move("/d/shaolin/luohan5");

	return 1;
}

#include "shizhe.h"