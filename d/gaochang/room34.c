
inherit ROOM;
int do_get(string arg);
int do_break(string);

void create()
{
    set("short", "��");
    set("long", @LONG
ǰ��ɽʯ��·���ѵ���ͷ��ֻ����ͷ���������⣬�߽���ʱ��ȴ��һ��ʯ��
�š����Ÿߴ��������������ţ�ֱ��һ��޴����ʯ��ʯ���������һ����ĸ���
�����������߶೤�Ĵִ���ť��ס��
LONG
    );
    set("exits", ([ 
        "south" : __DIR__"room33",
]));
    setup();
}
void init()
{
    object *obj;
    if (query("time")+1800<time() ){
        set("axe",1);
        set("time",time());
    }
obj=children(__DIR__"obj/goldaxe");    	
        add_action("do_get", "get");
add_action("do_break", "break");	
//   if (sizeof(obj)>1)        set("axe",0);         	
    if (query("axe")){
        set("item_desc",([
        "ʯ��": "�Ż��ϲ���һ��"+YEL+"�ƽ�"+NOR+"(Axe)\n",]));
     }else
        set("item_desc",([
        "ʯ��": "���Ⱥ��Ĵ�ʯ�ţ��ƺ������ܴ�����!\n",]));
}

int do_get(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (query("axe"))
        if( arg=="axe from men" || arg=="axe from ʯ��") {
             ob=new(__DIR__"obj/goldaxe");
            if (ob->move(me)){
                     message_vision("$N�γ�һ��"+YEL+"�ƽ�"+NOR+"��\n",me);
                    delete("axe");
                     set("item_desc",([
                     "ʯ��": "���Ⱥ��Ĵ�ʯ�ţ��ƺ������ܴ�����!\n",]));
             }else{
                     message_vision("$Nʹ���˳��̵����������Ż��ϵ�"+YEL+"�ƽ�"+NOR+"��Ȼ��˿������\n",me);
                     destruct(ob);
             }
             return 1;
       }
        return 0;
}
int do_break(string arg)
{
        object me,ob;
        object room;
        me = this_player();
    if (!arg || arg !="ʯ��")
        return notify_fail("��Ҫ�ٵ�ʲô��\n");
    ob=me->query_temp("weapon");
    if (!ob){
        message_vision("$N��������������������һ����˫ȭ����ʯ�ţ�\n\n���ʲô��Ҳû������\n",me);
        me->receive_damage("qi",100);
        return 1;
    }
    if (base_name(ob)!=__DIR__"obj/goldaxe"){
        message_vision("$N�߸߾������е�"+ob->query("name")+"����ʯ�ţ�\n\n���$N����һ��"+ob->query("name")+"���ַɳ���\n",me);
        ob->move(environment(me));
        me->receive_damage("qi",300);
        return 1;
    }
    if ((int)me->query_skill("force",1) < 600 ) {
       me->add_temp("tmark/��",1);
        message_vision("���ֻ��һ���ƺߣ�$N��ʯ�ŵķ����������ǰһ��....\n",me);
        me->receive_damage("qi",500);
        if (me->query_temp("tmark/��")>4)
        me->unconcious();
        return 1;
        }
    if (!( room = find_object(__DIR__"room35")) )
        room = load_object(__DIR__"room35");
    message_vision("$N���һ������"+ob->query("name")+"��ʯ��������¶��һ������\n$Nһ���������˽�ȥ��\n",me);
    me->set_temp("���", 1);
    me->delete_temp("marks");
    message("vision", "���洫��һ�����죬ʯ�ű��������ˡ�\n",room);
    message("vision", me->name()+"���Ŷ��롣\n",room,me);
    me->move(room);
    message("vision","һ���ʯ���������������ֱ���ס�ˡ�\n",this_object());
    message("vision","һ���ʯ���������������ֱ���ס�ˡ�\n",room);
    return 1;
}
