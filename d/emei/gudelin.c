// Room: /d/emei/gudelin.c ������ �ŵ���


#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ŵ���");
	set("long", @LONG
�����ľ���죬����е���������ͦ���Σ�֦Ҷ����������������ӵ��
��Ϊ��ʱһ��ɮ����������������һ�֣�ֲ��һ�꣬��ֲ�����ǧ�߰���ʮ
���꣬ʱ�ƹŵ��֡�Ҫ�ǲ���Ϥ���κ�������·��������һƬ�յأ���ֻ�
ľ׮(muzhuang)�ų�÷��ģ����
LONG
	);

	set("exits", ([
		"east" : __DIR__"bailongdong",
                "west" : __DIR__"gudelin2"
	]));

          set("objects", ([
              "/d/shaolin/npc/mu-ren" : 2,
        ]));
	set("outdoors", "emei");

	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

        mapping myfam;
        object me = this_player();
	int dex= this_player()->query_dex();

    if (arg != "muzhuang")  return command("jump "+arg);

    if (me->is_busy())
        return notify_fail("��������æ���ء�\n");

    if ( me->query("qi") <  15 )
         return notify_fail("�������̫���ˣ���Ҫ��Ϣһ���ˡ�\n");

         message_vision("$N�������ľ׮��\n", me);

    me->add("qi", -10+random(5));
    if ((!(myfam = me->query("family")) || myfam["family_name"] != "������") )
        {
        message_vision("$N����ľ׮����һȦ������۵�����������\n",me);
        return 1;
        }        
    if ((dex <= 15)&&(random(3)<2) || (dex > 15)&&(dex <= 18)&&random(2) )
     {
        message_vision("$Nҡҡ�λε�վ��ľ׮�ϣ����һ�����ȣ���ž����һ��ˤ�����������ʵʵˤ���˵��ϡ�\n",me);
        me->receive_damage("qi", 20, me);
        me->receive_wound("qi", 10, me);
        return 1;
     }

    else if ( dex <= 26) 
     {
   
        message_vision("$N����Ʈ�ݵ���ľ׮����һȦ��\n",me);  
        me->improve_skill("dodge", random(me->query_int()));
        write(HIR"���ƺ����Ṧ����һЩ�µ�������Ļ����Ṧ�����ˡ�\n"NOR);
        return 1;
      }
    else 
    {
    	message_vision("$N����ľ׮����һȦ��\n",me); 
        write(HIR"�����о�һ������\n"NOR);
        return 1;
    }
    
    return 1;
}
