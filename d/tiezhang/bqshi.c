// Room: /u/zqb/tiezhang/bqshi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
    ���ư��������Ʒ����Ṧ���ƣ��������Դ��д����ı������Թ���
�������İ���ʹ�á������������еĶ��Ǳ����ܣ����浶��ǹ������ꪡ���
���ᡢ������Ӧ�о��С�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"zoulang-1",
            ]));
  set("objects", ([ /* sizeof() == 4 */
	        "/clone/weapon/gangdao" : 1,
	        "/clone/weapon/gangjian" : 1,
	        "/clone/weapon/gangzhang" : 1,
	        "/clone/weapon/changbian" : 1,
	        "/clone/weapon/hammer" : 3,
	                ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
