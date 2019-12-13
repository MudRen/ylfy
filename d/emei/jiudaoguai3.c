// Room: /d/emei/jiudaoguai3.c ������ ��ʮ�ŵ���3

inherit ROOM;

void init();
int do_jump(string);

void create()
{
	set("short", "��ʮ�ŵ���");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹����һ��
����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡��ٲ��ڽ��±���
�������ڲ�Զ��ɽ���»��һ����̶(lake)��
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "northdown":__DIR__"jiudaoguai2",
                "southeast" : __DIR__"jiudaoguai4",
	]));

	setup();
}
void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{

	object me = this_player();
	int dex = this_player()->query_dex();

    if (arg != "lake") return command("jump "+arg);
	
    message_vision("$N��ಣ���һ���������������˳�ȥ��\n", me);
    
    if ((dex <= 23)&&(random(3)<2) || (dex > 23)&&(dex <= 26)&&random(2) )  
    {
    	message_vision("��������ˣ�һ������$Nƽƽ�ĵ�����ˮ�С�\n", me);
	tell_object(me, "��ֻ����һ�����ذ���ͷһ�����ࡣ\n");    
  		me->receive_damage("qi", 10);
   		
    } else if (dex <= 26)
    {
    	message_vision("$Nҡҡ�λε�����ˮ�У�����һ��޴���˻���\n", me);
    
    } else 
    {
    	message_vision("$N��һֻ���Ҽ���������ʮ��������Ծ��ˮ�У�ˮ�淺������С�˻���\n", me);
    }
    
    me->move(__DIR__"hudi");
    
    return 1;
}


