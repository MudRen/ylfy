inherit ROOM;
string look_out();
void create()
{
    set("short", "����֮��");
    set("long", @LONG
�������֮�ۡ�����ɽ�紵���������������ƺ�������������������ƮƮ���ɵĸо���
��֪����(out)����ͷ�ϣ����������ĸо���
LONG
    );
    set("exits", ([
    ]));
    set("item_desc", ([
"out"       :   (: look_out :),	
    ]));
    setup();
}
void init()
{
add_action("do_tiao", "tiao");    	
}
int do_tiao(string arg)	
{
    object me;
me = this_player();	
if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");          	
message_vision("$N��һ����һ������������ȥ��\n", me);	
me->move("d/city/guangchang.c");         	
message_vision("ֻ�����须��һ�����죬һ����������ϵ���������\n", me);	
//       if (wizardp(me)) {	
//  me->command(unset immortal);	
//       me->command(unset invisibility);	
me->command("chat ��������");	
//   me->delete_temp("last_damage_from");    	
me->set_temp("die_for","������������ˤ");       	
    me->die();
    return 1;
//      }	
}
string look_out()
{
return  "�������������ߴ������������ң���������硣\n"	
"�����̳��������۵ס���˵�˵�����ʦ��ɱ�ĵط���\n";
}

