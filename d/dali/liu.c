inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������ﲻʤ�ߡ�
����ϴ�������ۣ�����ҡŪ����֫����������ˡ�
���������������ŵ͡�
�߷����˴����������ѩů��ʱ�������������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yue",
  "south" : __DIR__"xue",
]));

        setup();
}
