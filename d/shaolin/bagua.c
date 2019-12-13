// Room: /d/shaolin/bagua.c
// Date: YZC 96/01/19
// Date: CLEANSWORD 96/05/19
inherit ROOM;
void create()
{
    set("short", "����������");
    set("long", @LONG
������Ǻ�Ĺ�������ġ�վ��������ܿ��������
�����Σ�ֻ����Χĺ�����������������������߼ʡ�һ����
�����籼�߰㴩����䣬�����������ס�����ż���������
�޽��������׵��ŵص������������һ����������˵����
�Ĺ���ɾ塣�������д���һ����̶(tan)����֮����ס�
LONG
    );
    set("item_desc", ([
        "tan":  "��̶�ߵ���ʯ�Ͽ����ĸ��޴�Ĺ�׭������ź�̶����\n"
            "�������С�֣��������ӽ��顱�� ̶�߶��Ǽ�Ӳ�������ң�\n"
            "̶ˮ�α�͸������Ϻ������ˮ����������һ�����ĵ�����ɫ��\n"
            "�߽����һ�ɳ��Ǻ������������  �ֿ��ƺ�ֻ�м�ʮ���\n"
            "��ϸ����ȥȴ��Խ��Խ�ֱ���޵���Ԩһ�㣡\n",
    ]));
    set("exits", ([
        "up" : __DIR__"andao3",
    ]));
set("objects", ([ /* sizeof() == 1 */	
"/kungfu/class/shaolin/hui-xin" : 1,      		
]));	
    setup();
}
void init()
{
        add_action("do_enter", "enter");
		add_action("discmds",({"qufeng"}));
}
int do_enter(string arg)
{
    object me;
    me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="tan" ) 
    {
                if( present("pishui zhu", me) ) 
        {
            message_vision("$Nȡ����ˮ���飬�����������һ�ݣ�Ծ�뺮̶֮�С�\n", me);
                    me->move("/d/shaolin/hantan1");
                    message("vision", "ֻ��ˮ�滩��һ���죬�ƺ�����ҲǱ��ˮ����\n",
                        environment(me), ({me}) );
        }
        else
        {
            tell_object(me, "��һ����ˮ�У�ֻ��ʴ�Ǻ�����ȫ��������ë�����룬��֫������ȫ��ľ��\n"
                    "�����ŵ����в����һ����������ס̶�ߵ���ʯ������ææ�����˳�����\n");
                    message("vision", me->name() + "�°���һ����ˮ�У����̴��һ�����������Ƶ����˳�������\n",
                        environment(me), ({me}) );
        }
        return 1;
    }
}   

int discmds()
{
	if(!present("fengjiang ping", this_player()))   	
		return notify_fail("ʲô��\n");
        if(this_player()->is_busy())
                return notify_fail("����һ��������û����ɡ�\n");
if(this_player()->query_temp("apply/name")) return notify_fail("�㻹����ȡ����߰�!\n");
	tell_room(environment(this_player()),HIM+this_player()->name()+"�ο���ƿ����������ƿǱ��������ʹ��ƿ�е�����ԶԶƮ�˿�ȥ��\nͻȻ����֮����������֪�����������һ��Ⱥ���.��.��.��.��.��.��.��.��.��\nǬ��Ǭ��λ��Ȼһ����תӿ��һ��Ī����������ֻ��ͷ�����Ͳ�֪����........����һ�и�����ƽ�������� \n \n"+NOR);
       this_player()->start_busy(5);
       return 1;
}
