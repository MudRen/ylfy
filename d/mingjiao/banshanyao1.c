// Room: banshanyao1.c

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
�����ϰ�ɽ�������Ŷ����ɽ����ߵ�ɽ�ᾲ����������
��ɽ�½�ɫ������ɹ��һƬ�����������ɾ�һ������ʲ��ϲ��
���£�����ƽ�����֣������������Ҽ䵴���ţ�������.....!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"banshanting",
  "east" : __DIR__"shanpo1",
  "northwest" : __DIR__"xiaolu-1",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

