// Room: /d/dali/dangpu.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺21ʱ50��23�롣

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˵������ϴ�ֶ���Ķĳ����衣�Է�����ͷ����ĶĿ͡����񷻵Ĺ�����Ҳ��
���������䵱�������������Ǹ���֮�����ʹ͵�С��������˵�����Ȼ�Ƕĳ���
������ȴ��ͯ�����ۡ����̹����ƣ�����һ�顣
LONG
	);
        set("item_desc", ([
                "sign": @TEXT
    �����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ����Ŀ���������
����(list)������(buy)������(value)���䵱(pawn)�����(redeem)����
��(sell)���ֻ�������Բ鿴������Ʒ����(look_item ��ƷӢ����,ͬ����Ʒ�������)��
TEXT
        ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nandajie1",
]));

        set("no_fight", 1);
        set("no_beg",1);

        set("objects", ([
                __DIR__"npc/zhou" : 1,
        ]));

	setup();
}
