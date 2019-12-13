// Room: /d/dali/duchang2.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺21ʱ32��59�롣

inherit ROOM;

void create()
{
set("short", "�ķ�����");
	set("long", @LONG
 һ�ۿ���ȥ������������ǽ�̻Իͣ��ûʸ���������̨���Ǵ����ģ�
�����ֵط�����ǧ���˰������ӣ�û�˻����ԩ��������������˴��СС
�Ķ�����ֻҪ��˵�����õĶľߣ����ﶼ�С�����(sign)һ�顣
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "

���ӵĶķ���

�����������ࣾ���������� ���������ƣ�

���ࣺ����������������������
������		��С	������������	һ��һ
����  		�Ĵ�	��������������	һ��һ
������		��Χ��	����������ͬ�㣩һ����ʮ��
��������        �ĵ���                  һ����

���ӣ�
�������������� ��������
����ʮ����С��

",
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"duchang1",
]));

        set("objects", ([
"/d/dali/npc/dice_thrower" : 1,	
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" && me->query_temp("gamble/amount") )
                return notify_fail("�㻹��������������߰�!\n");
        return ::valid_leave(me, dir);
}

void init()
{
        this_player()->delete_temp("gamble");
}
