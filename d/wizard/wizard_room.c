
inherit ROOM;
void create()
{
	set("short", "��ʦ��Ϣ��");
	set("long", @LONG
������ǡ�����������ʦ����Ϣ���ڣ��շ�ˢ��������ǽ���Ϲ�	
ͺͺ��ʲô��û�У����ӵ����������һ���ľ�����������һ��
��ʦ���Բ�(board)��
LONG );

	set("exits", ([ /* sizeof() == 1 */
	 	"west" : __DIR__"suimeng_room",
        "east" : __DIR__"meeting",
        "up" : __DIR__"wizard_job",
	 	"down" : __DIR__"guest_room"
	]));
        set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
