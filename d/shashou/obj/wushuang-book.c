inherit ITEM;

string* titles = ({
        "��˫����",
});

void create()
{
        set_name(titles[random(sizeof(titles))], ({ "wushuang jianpu", "shu", "book" }));    
        set("long", "
��˫�����ؼ���
");
        set_weight(200);       
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����˫���ס�\n");
                set("value", 500);
                set("material", "paper");
                set("no_drop",1);
                set("no_get",1);
                set("unique", 1);


        }
}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}    
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        int dzlevel; 
        int neili_lost;
        if (!(arg=="wushuang jianpu" ||arg=="book" || arg=="shu"))
        return 0;

        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (!id(arg)) { 
                write("��Ҫ��ʲô��\n");
                return 1;
        }
       
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        if( (int)me->query("neili") < neili_lost) {
                write("�������������޷�������ô������书��\n");
                return 1;
        }

               dzlevel = me->query_skill("wushuang-jian", 1);
        if( (int)me->query("combat_exp") < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
    if ( me->query_skill("wushuang-jian", 1) > 200) {
        write("���Ѿ��޷����Ȿ�������򵽸�������书�ˡ�\n");
 	return 1;}
        if ( me->query_skill("wushuang-jian", 1) > 100) {
                neili_lost = 5;
                me->receive_damage("jing", 15);
                me->set("neili",(int)me->query("neili")-neili_lost);
                me->improve_skill("wushuang-jian", (int)me->query_skill("parry", 1)/3+1);
                write("��������ϰ��˫�������书�ؼ����ƺ��е��ĵá�\n");
                return 1;
        }
        else  write("�����˫�����ȼ�̫�ͣ����򲻵�������Ĺ���\n");

        return 1;
}
