// Room: /d/dali/dongdajie1.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ31��11�롣

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵������
������ĵ���Ⱥ�����ֲβ�룬����������ȥ�Ҵң�ֻ�������ϵ�С��
ʱ����ʱ��������������ﵽ����ɢ���Ű������������ա�����ͨ�����
�Ƕ��ţ������͵��˴���ǵ����ġ�·����������������Ļ��ݡ�͸��һ
���꿪�����޵Ĳ軨�����Կ�ȥ����ᷢ��·��������һ��[1;32mҩ��[2;37;0m��·�ı�
����[1;32m����·[2;37;0m��
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbdajie1",
  "west" : __DIR__"guangchang",
  "east" : __DIR__"dongdajie2",
  "south" : __DIR__"yaopu",
]));

	set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/girl" : 1,
        __DIR__"npc/girl1" : 1,
]));

	setup();
}
