// Room: xiaoting.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����ͨ��������Ϣ�ĺ�Ժ��С�������ܰڷ���һЩ����Ļ��ݣ�
ɢ�����������㡣ǽ��������һЩ�����ֻ������߰ڷ��ż��ź�ľ��
��С���������ڴ���æ����֮�࣬������������ЪϢ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houyuan",
  "east" : __DIR__"shenghuo-tang",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


