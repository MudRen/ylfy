// by Amis 2006-9-23 20:18

#include <ansi.h>

void init()
{
		add_action("block_cmd","beg",1);
		add_action("block_cmd","steal",1);
		add_action("block_cmd","sleep",1);
		
		add_action("do_go","go");
		add_action("do_dig","digging",1);
		
		//this_player()->set_temp("marks/����", 1);

}



int block_cmd()
{
		object ob = this_object();
		if ( ob->query("����/liuxing") ){
		write("���ڸճ��ֹ����ǣ������в��ٴ���Χ�ۣ��㻹��������ɣ�\n");
    return 1;
  	}
}

int do_dig()
{
		object obj,ob = this_object(),me = this_player();
		
		if ( !ob->query("����/liuxing") )
		return 0;	

    if ( !(present("tie qiao", me)) && !(present("tie chan", me)))
        return notify_fail(YEL"\nû�й������ڵö��𣿣�\n"NOR);

    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("����æ���أ�\n");     
        
		if ( me->query("jing") < 150 )
		return notify_fail("��ʵ��̫���ˣ�ЪЪ�ɣ�\n");	
		
		if ( me->query("jing") < 200 && random(2)==1 )
		return notify_fail("��ʵ��̫���ˣ�ЪЪ�ɣ�\n");
			
		message_vision("$N�������£���ʼһ���������ҡ�\n", me);		
				
		if ( random(999)==1 && random(me->query("kar")) > 32 )//�����������

		{
				obj=new("/clone/item/zuiyue-xuanjing");
				obj->move(me);
				message_vision(HIC"$N���ڼ��Ȼ����һ���쳣��Ӳ�����壬�ٳ���һ������Ȼ��һ���"+obj->query("name")+"��\n"NOR, me);
				write(HIG"�㾹Ȼ�����˼����ѵ�һ���Ĳ��ϣ���ֱ��ϲ�����˷��ޱȣ�\n"NOR);		
				return 1;
		}
		
		if ( random(200)==1 && random(me->query("kar")) > 29 )//��û�����ʯ
		{
				obj=new("/clone/gem/gem");
				obj->move(me);
				message_vision("$N����ͷ��Ȼ��һ�����������ǣ��ٳ���һ������Ȼ�ǿ�"+obj->query("name")+"��\n", me);
				return 1;
		}
		
		if ( random(10)==1 && me->query("kar") > 1 )//��ú�����
		{
				obj=new("/clone/map/obj/hanyu-jingtie");
				obj->move(me);
				message_vision("$N����ͷ��Ȼ��һ�����������ǣ��ٳ���һ������Ȼ�ǿ�"+obj->query("name")+"��\n", me);
				return 1;
		}
		if ( random(100)==1 && random(me->query("kar")) > 29 )//������Ƴ��
		{
				obj=new("/clone/map/obj/longwen-chijin");
				obj->move(me);
				message_vision("$N����ͷ��Ȼ��һ�����������ǣ��ٳ���һ������Ȼ�ǿ�"+obj->query("name")+"��\n", me);
				return 1;
		}
		if ( random(50)==1 && random(me->query("kar")) > 25 )//�����������(��)
		{
				obj=new("/clone/map/obj/jingang-shi");
				obj->move(me);
				message_vision("$N����ͷ��Ȼ��һ�����������ǣ��ٳ���һ������Ȼ�ǿ�"+obj->query("name")+"��\n", me);
				return 1;
		}

		me->receive_damage("jing", 50 + random(50) );
    me->start_busy(5);
		return 1;
}

