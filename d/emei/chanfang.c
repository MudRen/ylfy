//  /d/emei/chanfang.c ����

inherit ROOM;

void create()
{
        set("short","����");
	set("long", @LONG
������һ�����ɮ�ڲβ�����ϰ�ĵط������ڰ���ܼ򵥣�������һ��
�ܴ���񴲺�һ�������⣬�������������ϸ��ǽ�Ͽ�ȥ���·���Կ���
ǽ���Ͽ�һЩ���ġ��������м�λ��ͱȽ�����׼ҵ��ӣ��ڱ�Ŀ������
LONG
	);
        set("set_jingzuo",1);
	set("exits", ([ /* sizeof() == 3 */
                "west": __DIR__"baoguosi",
		]));

	set("objects",([
               "/d/emei/npc/sumengqing": 1,
	]));


	setup();
}
