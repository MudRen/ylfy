// Room: banshanting.c

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
�ϵ����ϣ������и�С�������������������˸�̾�佨��
��������������ɽ���ġ�������ȥ��ֻ��ӭ�����һ��������
���������ӣ�к����ȣ����ƾ�ֹһ�㣬�����������˿��龰
��ͼ��������ǧ�ȣ�����һ�����٣����̴�é�Ἰ�䣬С��һ
Ĩ��ʫ�黭�⡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"shanlu1",
  "north" : __DIR__"banshanyao1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

