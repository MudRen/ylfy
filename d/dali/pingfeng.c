inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
���������Ͽ񾢲��飺
�ﻪ��̩��������������ѿ����̣����������ࡣһ���һ�����񣬰�Ϫ��ˮ����
����������꣬�������顣��ɹ�����ޣ�����̦���ᡣɽɫ��ά��Ũ����������������
�ᡣ�������������ͣ�������ȴ���顣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mingyu",
  "south" : __DIR__"garden",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/beggar" : 1,
]));

        setup();
}
