// Room: /t/wanjiegu/road4.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�����ϵĹٵ�����ͨ����ǣ����治Զ�����Կ�������ĳ���
��������������������ַǷ����иϵ��ģ��о��̵ģ�Ҳ��������������
�ֺ��ܡ�

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
           "north" : "/d/kaifeng/dadao1",   	
            "south" : __DIR__"road3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
