// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
    set("short", "����̨");
    set("long", @LONG
�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ�
�������������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨��
�ڷ��ź����������������ڴ��������¡�̨�ϸ߸�����һ���죬
���飺�����е� �ĸ����֡� �������Ҹ���������λ������ʿ����
�߶�����һ���Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ�������
LONG
    );
        set("valid_startroom", 1);
    set("exits", ([
        "down" : __DIR__"fengchan-new",
        "east" : __DIR__"xiayi",
        "west" : __DIR__"zhengqi",
    ]));
    set("objects",([
                "/d/taishan/npc/meng-zhu" : 1,
"/d/taishan/obj/bingqipu" : 1,     	
        __DIR__"npc/wei-shi1" : 2,
    ]));
        set("no_clean_up", 1);
    set("outdoors", "taishan");
    setup();
set("item_desc", ([
        "����" : "�㿴�ſ��ź�Ȼ���ֱ���������Щ����,Ҳ���������ʲô����,����������������,˭���Ҷ���...,��˵�����ر�ϲ����Ķ���,Ҳ��������ʺ��һ���˾����㵱������,���������?\n",
    ]) );
    setup();
}
void init()
{
    add_action("do_lashi", "lashi");
}
int do_lashi(string arg)
{
    int n;
    object me = this_player();
    if( !arg || arg!="����" )
    {
        write("��Ҫ��ش�С�㣡\n");
        return 1;
    }
    message_vision("$N������������������ͷ������һ�ѳ������ŵ�ʺ��\n", this_player());
   /* if ((me->query("family/family_name") == "����¥") && (me->query("family/master_id") == "flypp"))
    {
        me->move("/d/flypproom/fightroom87");
        return 1;
    }*/
    n = (int)me->query("neili");
    if (n >= 500000)
    {
        message_vision(
        "ͻȻ�����������嶶�˼���(����о�ͦˬ),������ĵ�����ȥ,��������һ�����ݣ�\n", this_player());
        set("exits/up", "/d/flypproom/fightroom87");
        this_player()->set("neili",n-2000);
        remove_call_out("close");
        call_out("close", 3, this_object());
    }
    else
    {
        message_vision(
        "��������˵��:����������ͷ����ʺ,���Ĳ��ͷ���??\n", this_player());
        this_player()->set("neili",0);
        this_player()->unconcious();
    }
    return 1;
}
void close(object room)
{
    message("vision","��������һ��˯��,����������,һ���ָֻ�������\n", room);
    room->delete("exits/up");
}
int valid_leave(object me, string dir)	
{        		
	return ::valid_leave(me, dir);	
}

void update_here()
{
	remove_call_out("reset");
	call_out("reset", 1);
}