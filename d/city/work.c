
inherit "/inherit/room/work";

void create()
{
	set("short", "����ӹ���");
	set("long", @LONG
����һ�����ӹ����������ǹ����ѿǳ��׵ĵط����׳��ϰ���һ
��һ����֪����ʮ�־����ĸ��ݵ������ˣ����Ǵ���һ����Ц�������
�������������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��
LONG );
	set("no_sleep_room",1);
	set("no_fight",1);	
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"dongmen",
	]));
	set("item_desc", ([
		"sign": @TEXT
��������ȱ���֣������Ӷһ���̹����ɻ
work     ��ʼ������
TEXT]) );
	set("no_magic", 1);
	set_heart_beat(5+random(get_system_config(DATA_CONFIG_DIR "work.h", "do_heart_times")));
	setup();
}
