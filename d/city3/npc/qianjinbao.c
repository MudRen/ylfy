// qianjinbao.c Ǯ����
// change By zhm@silversand_mud

#include <ansi.h>
inherit NPC;
inherit F_BANKER;
int pieban(object me);
int pieqian(object me);
int piedan(object me);
int pieshuang(object me);
int piesan(object me);
int do_yao();
int do_kai();
int yesorno();
string cstr(int i);

//ȫ�̱���
int sumi,summ;
int thecash;
int m1,m2,m3,i1,i2,i3,j1,j2,j3,k1,k2,k3;

void create()
{
        set_name("Ǯ����", ({ "qian jinbao", "qian","jinbao" }));
        set("gender", "����");
        set("long",
                "һ�������Բ�����ӣ�С�۾�����������ʲô���������һ˿��Ц��\n"
        );
        set("age", 32);
        set("title",HIW"��ı�ʤ"NOR);     
        set("nickname",CYN"��ǧ��"NOR);  
         set("combat_exp", 100000);
        set("immortal",1);

        set("inquiry", ([
                "��ʥ"   : "�����ҵ�ʦ����\n",  
                "��" : "Ҫ�ľͶģ�Ī˵�ϻ���\n",
         ]) );  

        set("book_count",1);

        setup();

        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
       if (base_name(environment())!=this_object()->query("startroom")) return;
        add_action("do_yao","yao");
        add_action("do_kai","kai");
        add_action("do_convert", "convert");
        add_action("do_convert", "huan");
}

int accept_object(object who, object ob)
{
        object me=this_player();

        if (who->query_temp("tmark/Ѻ")) {
                        message_vision(HIG"Ǯ��������ؿ���$N˵�����Ѿ��¹�ע��ѽ��\n"NOR,who);
                 return 0;   
                }
     if (query("book_count") ) {
        if (ob->query("money_id")) {
                        if (ob->value()<100) {
                        message_vision(HIR"Ǯ������мһ�˵ؿ���$N��˵����Ҫ��ע����һ�����ӣ�\n"NOR,who);
                        return 0;
                }
                 if (ob->value()>100000) {
                        message_vision(HIR"Ǯ����ҡ��ҡͷ����$N˵�������ﲻ��ӭ��עһ���������ע10���ƽ�\n"NOR,who);
                        return 0;
                }
                add("book_count",-1);
                thecash = ob->value();
               who->set_temp("tmark/Ѻ",1);
                sumi=summ=0;
                i1=i2=i3=m1=m2=m3=j1=j2=j3=k1=k1=k3=0;
                message_vision(HIY"Ǯ����ߺ�ȵ���$N��ע��ɣ������ˡ�\n"NOR,who);
                i1 = 1+random(13413)%13;
                i2 = 1+random(23413)%13;
            if (random(10)==5)
                i1 = i2 = 13;
            if (random(10)==4)
        { i1=1; i2=random(4)+10; }
               message_vision("\n"+WHT"ׯ�ҵ�����:    ��   ��   "+cstr(i1)+"\n"NOR,who);
                if (i1>10) j1=10;
                else j1=i1;
                if (i2>10) j2=10;
                else j2=i2;
                sumi = j1 + j2;

                m1 = 1+random(11213)%13;
                m2 = 1+random(23313)%13;
   message_vision(HIC"\n$N������:    "+cstr(m1)+"   ��   "+cstr(m2)+"\n"NOR,who);     
                if (m1>10) k1=10;
                else k1=m1;
                if (m2>10) k2=10;
                else k2=m2;
                summ = k1+k2;
                if ((summ == 21) || ((summ==11) && (m1==1 || m2==1)) ) {
                        message_vision(HIR"����BLACKJACK��$N������������$N��������\n"NOR,who);
                        remove_call_out("destroying");
                        call_out("destroying", 0, me, ob);
                        piesan(who);
                        set("book_count",1);
                }
                else {
message("vision",HIW"\n\nС�Ŀ��������ƣ���Ҫ��(yao),�����뿪��(kai)��\n"NOR,who);
                } 

                remove_call_out("destroying");
                call_out("destroying", 0, me, ob);
                return 1;
        }
        } // if (query("book_count"))
        else {
message_vision("�Ѿ���������Ǯ�����Զ��ˣ�����$N�õ��²����ˡ�\n",who);
                return 0;
        }
}

int do_yao()
{
        object me=this_player();
        int m3;

        if (!me->query_temp("tmark/Ѻ")) {
message_vision(RED"Ǯ�������ͷ�������$Nһ�ѣ�ȥȥȥ��ע��û���أ�Ҫʲô�ư���\n"NOR,me);
                return 1;
        }
        m3 = 1+random(6353)%13;
        message_vision(HIM"\n$N��Ҫһ�Ű����ðɣ���$N������:   "+cstr(m3)+"\n\n"NOR,me);
        if (m3>10) k3=10;
        else k3=m3;
        summ = summ+k3;
        if(m1==1 || m2==1 || m3==1)
                if(summ<12)
                        summ=summ+10;

        if (summ>21) {
                if (random(10)>9){
       message_vision(HIG"Ǯ������У���$N�����Ǳ���,�����ҵ�����Σ���\n"NOR,me);       
message_vision(HIB"Ǯ����һ�����ϵ��ƣ��ǳ����εص��������ҵ���Ҳ�Ǳ��ˣ�ׯ����$N30%�������ѣ�\n"NOR,me);
              pieban(me);
               }
           else{  
              message_vision(HIG"Ǯ����Ц������˵��������˼��$N�����Ǳ��ˣ�����Ӯ�ˡ�\n"NOR,me);
      }
      }
        else {
                if (summ==21) {
                        message_vision(HIR"Ǯ����������ɫ�����ǣ����㣿$N������������$N˫������\n"NOR,me);
                        pieshuang(me);  
      }
//    }
                else {
                        sumi = yesorno();
                        if(i1==1 || i2==1 || i3==1) {
                                if(sumi<12)
                                        sumi=sumi+10;
                                if(sumi>21)
                                        sumi=sumi-10;
                        }
        
                        if (sumi>21 || sumi<summ) {
                                if (sumi>21)
                                        message_vision(HIY"Ǯ����ɥ����˵���ҵ���"+cstr(i1)+cstr(i2)+cstr(i3)+"�Ǳ��ˣ���$N��\n"NOR,me);
                                else
                                        message_vision(HIY"Ǯ��������һ�Ѱ����������ϣ�����"+cstr(i1)+cstr(i2)+cstr(i3)+"��û$N���\n"NOR,me);
                                pieqian(me);
                        }
                        else {
                        if (sumi == summ) {
//message_vision(HIB"Ǯ�����ǳ����εص�����������"+cstr(i1)+cstr(i2)+cstr(i3)+"������ͬ�㣬û��׬$N�ģ�\n"NOR,me);
message_vision(HIB"Ǯ����������Ц����̫���ˣ�����"+cstr(i1)+cstr(i2)+cstr(i3)+"����ͬ�㣬ׯ����$N30%��������!\n"NOR,me);
                                pieban(me);
                       // piedan(me);
                    } 
                        else {
                                message_vision(HIG"Ǯ����Ц������˵���ҵ�����"+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
                              message_vision(HIG"Ǯ���������˷ܵı��飺�����ô���������,��Ӯ$N��Ǯ,�治����˼��\n"NOR,me);
                        }
                        } 
                }
        }

        me->set_temp("tmark/Ѻ",0);
        set("book_count",1);
        return 1;
}

int do_kai()
{
        object me = this_player();
        if (!me->query_temp("tmark/Ѻ")) {
message_vision(RED"Ǯ�������ͷ�������$Nһ�ѣ�ȥȥȥ��ע��û���أ���ʲô�ư���\n"NOR,me);
                return 1;
        }
        message_vision(HIM"\n$N����һ�ᣬ����������һ�ӣ����ðɣ��ҾͿ������ˣ���\n\n"NOR,me);  

        summ = summ+k3;
        if(m1==1 || m2==1 || m3==1)
                if(summ<12)
                        summ=summ+10;

        sumi = yesorno();
        if(i1==1 || i2==1 || i3==1) {
                if(sumi<12)
                        sumi=sumi+10;
                if(sumi>21)
                        sumi=sumi-10;
        }
        
        if (sumi>21 || sumi<summ) {
                if (sumi>21)
                        message_vision(HIY"Ǯ����ɥ����˵���ҵ���"+cstr(i1)+cstr(i2)+cstr(i3)+"�Ǳ��ˣ���$N��\n"NOR,me);
                else
                        message_vision(HIY"Ǯ��������һ�Ѱ����������ϣ�����"+cstr(i1)+cstr(i2)+cstr(i3)+"��û$N���\n"NOR,me);
                pieqian(me);
                }
        else {
                if (sumi == summ) {
               // message_vision(HIB"Ǯ�����ǳ����εص�����������"+cstr(i1)+cstr(i2)+cstr(i3)+"������ͬ�㣬û��׬$N�ģ�\n"NOR,me);
               // piedan(me);
message_vision(HIB"Ǯ����������Ц����̫���ˣ�����"+cstr(i1)+cstr(i2)+cstr(i3)+"����ͬ�㣬ׯ����$N30%��������!\n"NOR,me);
                           pieban(me);

                }
                else {
                        message_vision(HIG"Ǯ����Ц������˵���ҵ�����"+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
                        message_vision(HIG"Ǯ���������˷ܵı��飺�����ô���������,��Ӯ$N��Ǯ,�治����˼��\n"NOR,me);
                }
        } 

        me->set_temp("tmark/Ѻ",0);
        set("book_count",1);
        return 1;
}
int pay_player(object who,int amount)
{
    object ob;
    int total;
    if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
        if (!ob=present("gold_money", who)){
                    ob = new(GOLD_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/10000+total);
                amount %= 10000;
    }
    if( amount/100 ) {
        if (!ob=present("silver_money", who)){
                    ob = new(SILVER_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/100+total);
        amount %= 100;
    }
    if( amount ) {
        if (!ob=present("coin_money", who)){
            ob = new(COIN_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount+total);
    }
    who->set_temp("tmark/Ѻ",0);
    return 1;
}


int piedan(object me)
{
        pay_player(me,thecash);
        return 1;
}

int pieban(object me)
{
       pay_player(me,thecash*7/10); 
        return 1;
}

int pieqian(object me)
{

        pay_player(me,thecash*2);
        return 1;
}

int pieshuang(object me)
{

        pay_player(me,thecash*3);
        return 1;
}

int piesan(object me)
{

        pay_player(me,thecash*4);
        return 1;
}


int yesorno()
{
       
        if (i1==1 || i2==1)
                if(sumi<12) 
                        sumi=sumi+10;

        if (sumi>17) return sumi;
        else {
                if (sumi<14) {
                        i3 = 1+random(13);
                        if (i3>10) j3=10;
                        else j3=i3;
                        return sumi+j3;
                }
                else {
                        if(random(21)>10) {
                                i3 = 1+random(13);
                                if (i3>10) j3=10;
                                else j3=i3;
                                return sumi+j3;
                        }
                        else return sumi;
                }
        }
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

string cstr(int i)
{
        switch(i) {
                case 1:
                        return "��";
                case 2:
                        return "��";
                case 3:
                        return "��";
                case 4: 
                        return "��";
                case 5:
                        return "��";
                case 6:
                        return "��";
                case 7:
                        return "��";
                case 8:
                        return "��";
                case 9:
                        return "��";
                case 10:
                        return "10";
                case 11:
                        return "��";
                case 12:
                        return "��";
                case 13:
                        return "��";
                default:
                        return "";
        }
}

