// Room: /d/dali/fangjudian.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺22ʱ8��7�롣

inherit ROOM;

void create()
{
        set("short", "Ѧ�ǳ�����");
        set("long", @LONG
����һ�����ֺŵĳ����̣���������˸�ʽ���������
�񡢾˿������Ƥ������춷��л������ȹ��ˮ��ɫ
�ް�������ɫ�Ż���������һ���㡣ǽ�Ϲ��Ÿ�����(paizi)��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
]));
        set("item_desc", ([
                "paizi": "��ӭ�����·���\n",
        ]) );

        set("objects", ([
                __DIR__"npc/caifeng" : 1,
        ]));

        setup();
}

