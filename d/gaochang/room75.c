// Room: /d/gaochang/room75.c
// by mei

inherit ROOM;

void create()
{
        set("short", "ѩ��");
        set("long", @LONG
���������Ǹ߸��������շ壬��������ɼ�ϥ�Ļ�ѩ��
LONG
);

        set("exits", ([ 
  "out" : __DIR__"room63",
]));

    if (random(10)>5)
        set("objects", ([ 
        __DIR__"obj/xuecan" : 1,
        __DIR__"obj/xueshen" : 1,
]));

        setup();
}
void init()
{
    add_action("do_prize", "prize");
    add_action("do_chip", "chip");
}
int do_chip(string arg)
{
    object weapon,me=this_player();
    int power;
    if (!arg || arg!="��")   return 0;
    if (!query("hanyu") || query("chip"))    return notify_fail("�����Ѿ������俪�ˡ�\n");
    weapon=me->query_temp("weapon");
    if (!weapon)    return notify_fail("���ֿ��²��ܰѱ��ÿ��ɣ�\n");
    power=weapon->query("weapon_prop/damage")+me->query_str()+weapon->query_weight()/1000;
    set("chip",1);
    switch (weapon->query("skill_type")){
        case "sword":
            if (power > 1200){
                message_vision("$N�����е�"+weapon->name()+"ʹ����������ȥ��\n",me);
                message_vision("����һ�±�$N�俪�ˣ�һ���̹�ֱ����ʡ�\n",me); 
                message("vision","������¶��һ���̹⾧Ө��ǧ�꺮��\n",this_object()); 
                return 1;
            }        
            break;
        case "blade":
            if (power > 1000){
                message_vision("$N�����е�"+weapon->name()+"ʹ����������ȥ��\n",me);
                message_vision("����һ�±�$N�俪�ˣ�һ���̹�ֱ����ʡ�\n",me); 
                message("vision","������¶��һ���̹⾧Ө��ǧ�꺮��\n",this_object()); 
                return 1;
            }        
            break;
        case "dagger":
            if (power > 1800){
                message_vision("$N�����е�"+weapon->name()+"ʹ����������ȥ��\n",me);
                message_vision("����һ�±�$N�俪�ˣ�һ���̹�ֱ����ʡ�\n",me); 
                message("vision","������¶��һ���̹⾧Ө��ǧ�꺮��\n",this_object()); 
                return 1;
            }
            break;
        case "whip":
            if (power > 2000){
                message_vision("$N�����е�"+weapon->name()+"ʹ�������ϻ�ȥ��\n",me);
                message_vision("����һ�±�$N�俪�ˣ�һ���̹�ֱ����ʡ�\n",me); 
                message("vision","������¶��һ���̹⾧Ө��ǧ�꺮��\n",this_object()); 
                return 1;
            }        
            break;
        case "chui":
        case "hammer":
            if (power > 800){
                message_vision("$N�����е�"+weapon->name()+"ʹ����������ȥ��\n",me);
                message_vision("����һ�±�$N�俪�ˣ�һ���̹�ֱ����ʡ�\n",me); 
                message("vision","������¶��һ���̹⾧Ө��ǧ�꺮��\n",this_object()); 
                return 1;
            }        
            break;
        case "staff":
        case "club":
            if (power > 1500){
                message_vision("$N�����е�"+weapon->name()+"ʹ����������ȥ��\n",me);
                message_vision("����һ�±�$N�俪�ˣ�һ���̹�ֱ����ʡ�\n",me); 
                message("vision","������¶��һ���̹⾧Ө��ǧ�꺮��\n",this_object()); 
                return 1;
            }        
            break;
        default:    
            message_vision("����һ�¾ͱ�$N�Ҹ����顣\n",me);
            set("hanyu",0);
            set("chip",1);
            return 1;
    }
    set("chip",0);
    message_vision("$N�����е�"+weapon->name()+"ʹ����������ȥ��\n",me);
    message("vision","������ȴΡȻ������\n",this_object());
    return 1;
}
int do_prize(string arg)
{
    object ob,me=this_player();
    
    if (!arg || arg!="����")   return 0;
    if (!query("hanyu") || !query("chip")) return 0;
    ob=new(__DIR__"obj/hanyu");
    ob->move(me);
    set("hanyu",0);
    delete("item_desc");
    message_vision("$N���˵ذѺ���ӱ������˳�����\n",me);
    return 1;
}
void reset()
{
    ::reset();
    set("hanyu",1);
    set("chip",0);
    set("item_desc", ([
        "��ѩ" : "    �ڻ�ѩ�����룬�д��ط����˺ܺ��һ�����\n��������ɫ��������(chip)��������\n", 
])); 
}

