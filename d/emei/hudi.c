// Room: /d/emei/hudi.c ����
// create by host dec,20 1997

inherit ROOM;

void init();
int do_swim();

void create()
{
        set("short", "����");
	set("long", @LONG
��������̶�ײ���������ȥ�����ܳ����������ɫ��ˮ������ˮ��
��ͣ��������ζ���������ϵ���ˮ�ݴ���������ȥ����ϸ��ȥԼĪ��
�Կ���ǰ����һ�����ڣ��Ӷ��ڲ�ʱ������͸�롣
LONG
	);
        set("exits", ([
	]));
	setup();
}
void init()
{
	add_action("do_swim", "swim");
}

int do_swim()
{

	object me = this_player();
	int dex = this_player()->query_dex();

    message_vision("$N�����³�һ���������͵��򶴿���ȥ��\n", me);
    
    if ((dex <= 15)&&(random(3)<2) || (dex > 15)&&(dex <= 18)&&random(2) )  
    {
    	message_vision("ͻȻһ�ɾ޴�İ���ӿ�˹�����һ�����ذ�����$N������˰��ϡ�\n", me);
       me->move(__DIR__"jiudaoguai2");
   		
    } else if (dex <= 23)
    {
    	message_vision("$N�����ε����ڣ�ͻȻһ�ɰ���ӿ�˹�����$N������˰��ϡ�\n", me);
       me->move(__DIR__"jiudaoguai2");
    } else 
    {
    	message_vision("$N�ɿ�Ĵ������ڣ��ε��˶��ڵ���һ�档\n", me);
       me->move(__DIR__"dongkou");
    }
    
    
    
    return 1;
}
