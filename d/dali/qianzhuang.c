// Room: /d/dali/qianzhuang.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ37��25�롣

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ������̨����һ�����ӣ�������
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qian.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dbdajie1",
]));

        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�
convert(huan)     �һ�Ǯ�ҡ�
deposit(cun)      ��Ǯ��
withdraw(qu)      ȡǮ��
check(cha)        ��ѯ��
TEXT
        ]) );

  set("no_fight",1);
	setup();
}
