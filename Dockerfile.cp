FROM openjdk:17
EXPOSE 8080
ARG JAR=spring-petclinic-3.1.0-SNAPSHOT.jar
COPY ./$JAR /app.jar
ENTRYPOINT ["java","-jar","/app.jar"]