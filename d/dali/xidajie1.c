// Room: /d/dali/xidajie1.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ28��57�롣

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵������
������ĵ���Ⱥ�����ֲβ�룬����������ȥ�Ҵң�ֻ�������ϵ�С��
ʱ����ʱ��������������ﵽ����ɢ���Ű������������ա�����ͨ�����
�����ţ������͵��˴���ǵ����ġ�·����������������Ļ��ݡ�͸��һ
���꿪�����޵Ĳ軨�����Կ�ȥ����ᷢ��·��������һ��[1;32m��ջ[2;37;0m��·�ı�
����[1;32mϦ��·[2;37;0m��
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xbdajie1",
  "west" : __DIR__"xidajie2",
  "east" : __DIR__"guangchang",
  "south" : __DIR__"kezhan",
]));

	set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/girl" : 1,
        __DIR__"npc/girl1" : 1,
]));

	setup();
}
