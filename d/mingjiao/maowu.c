// Room: maowu.c

inherit ROOM;

void create()
{
        set("short", "é��");
        set("long", @LONG
�㴩����������ɽ������Զ����һé�ݡ�Զ����ȥ��ǧҶ
��̨����ɽ�Դ䣬��Ϫ���٣�ӳ����䣬��Ŀ�̲�ǧ�ӳ��
�������롣������̦�̲ݣ���������������ͷһ�գ�˿������
���ȣ������������ˣ�����決죬��׺��䣬ֱ��������Դ��
LONG
        );
       set("no_fight", 1);
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"liupeng",
  "southwest" : __DIR__"diecong4",
]));
        set("objects", ([ 
  __DIR__"npc/hu" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

