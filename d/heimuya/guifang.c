// Room: /d/heimuya/guifang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�뷿");
	set("long", @LONG
���ڻ��Ž��أ�֬��Ũ���˱ǣ�����һ����ױ̨������һ�ˣ����ۺ���
������������һ���廨���ܣ����ֳ���һö�廨�룬̧��ͷ�������в���֮ɫ��
��������˺��룬���Ͼ�Ȼʩ��֬�ۣ������Ǽ�����ʽ���в��С�Ů��Ů����
ɫ֮�������Ǵ���Ů�����ϣ�Ҳ�Ե�̫���ޡ�̫������Щ��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaoshe",
]));
 set("objects", ([
                __DIR__"npc/dongfang" : 1,
           ]));                                                    


	setup();
	replace_program(ROOM);
}
