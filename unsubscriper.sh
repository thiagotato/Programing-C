DATE=`date "+%Y%m%d"`

DIR=/var/log/unsubscriber-util/

BI=/home/mnt/bilogs

LOGS=/home/mnt/opr/logs/$HOSTNAME

JAVA_OPTS="-Xms1024m -Xmx1024m -XX:MaxPermSize=512m -XX:NewSize=512m -XX:MaxNewSize=512m -Duser.timezone=America/Sao_Paulo"

APP_OPTS="$JAVA_OPTS -Dlogprefix=claro_cancelamento_appsclub_vert_ -Dcom.bemobi.unsubscriberutil.sourcedir=/home/mnt/bilogs/Subscription/claro_cancelamento_appsclub_vert_$DATE.txt"

        /AppServer/jdk1.6.0_37/bin/java -jar $APP_OPTS /AppServer/unsubscriber/unsubscriber-util.jar

                sleep 3600;

                        cd $DIR
                        a=claro_cancelamento_appsclub_vert_$DATE-error.txt
                        if test -f $a ; then
                        cp $a $BI/Subscription/
                                 if [ "$?" -eq "0" ] #testa resultado do ultimo comando.
                                        then
                                                if [ -f $BI/Subscription/$a ] # testa se arquivo foi criado(double check).
                                                        then
                                                                if [ -s $BI/Subscription/$a ] #teste se tamanho é maior que zero(triple check).
                                                                        then
                                                                                        echo "-- `date +"%d-%m-%Y"` - Arquivo copiado $BI/Subscription/$a -- SUCESSO" >> $LOGS/bilogs.$MES.log
                                                                        else
                                                                                echo "-- `date +"%d-%m-%Y"` - Arquivo zerrado $BI/Subscription/$a -- ERRO" >> $LOGS/bilogs.$MES.log
                                                                fi
                                                        else
                                                                echo "-- `date +"%d-%m-%Y"` - Arquivo não existe no destino $BI/Subscription/$a -- ERRO" >> $LOGS/bilogs.$MES.log
                                                fi
                                        else
                                                echo "-- `date +"%d-%m-%Y"` - Arquivo não foi copiado $BI/Subscription/$a -- ERRO" >> $LOGS/bilogs.$MES.log
                                fi
                        fi        	



                        b=claro_cancelamento_appsclub_vert_$DATE-success.txt
                        if test -f $b ; then
                        cp $b $BI/Subscription/
                                 if [ "$?" -eq "0" ] #testa resultado do ultimo comando.
                                        then
                                                if [ -f $BI/Subscription/$b ] # testa se arquivo foi criado(double check).
                                                        then
                                                                if [ -s $BI/Subscription/$b ] #teste se tamanho é maior que zero(triple check).
                                                                        then
                                                                                        echo "-- `date +"%d-%m-%Y"` - Arquivo copiado $BI/Subscription/$b -- SUCESSO" >> $LOGS/bilogs.$MES.log
                                                                        else
                                                                                echo "-- `date +"%d-%m-%Y"` - Arquivo zerrado $BI/Subscription/$b -- ERRO" >> $LOGS/bilogs.$MES.log
                                                                fi
											   			else
                                                                echo "-- `date +"%d-%m-%Y"` - Arquivo não existe no destino $BI/Subscription/$b -- ERRO" >> $LOGS/bilogs.$MES.log
                                                fi
                                        else
                                                echo "-- `date +"%d-%m-%Y"` - Arquivo não foi copiado $BI/Subscription/$b -- ERRO" >> $LOGS/bilogs.$MES.log
                                fi
                        fi        

                               #matar o JOB no final
